/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:06:39 by kethouve          #+#    #+#             */
/*   Updated: 2024/02/19 15:02:24 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*clear_res(char	*src)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[j] && src[j] != '\n')
		j++;
	if (src[j] == '\n')
		j++;
	while (src[i])
		i++;
	new_line = malloc(((i - j) + 1) * sizeof(char));
	if (!new_line)
		return (0);
	i = 0;
	while (src[j])
		new_line[i++] = src[j++];
	new_line[i] = '\0';
	free(src);
	src = NULL;
	return (new_line);
}

char	*get_txt(int fd, char *res)
{
	char	*tmp;
	int		readed;

	readed = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	tmp[0] = '\0';
	if (!tmp)
		return (0);
	while (!ft_strchr(tmp, '\n') && readed != 0)
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed <= 0 && (res == NULL || res[0] == '\0'))
		{
			free(tmp);
			free(res);
			return (0);
		}
		tmp[readed] = '\0';
		res = ft_strjoin(res, tmp);
	}
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (free(res), res = NULL, NULL);
	if (res != NULL)
		res = clear_res(res);
	res = get_txt(fd, res);
	if (res == NULL)
	{
		free(res);
		return (0);
	}
	line = ft_get_line(res);
	return (line);
}
