/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:30 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/06 18:01:43 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_tester(t_tester *map_test, int y, int x)
{
	if (map_test->map[y][x] == 'C')
		map_test->c++;
	if (map_test->e < 1 && (map_test->map[y + 1][x] == 'E'
		|| map_test->map[y - 1][x] == 'E' || map_test->map[y][x + 1] == 'E'
		|| map_test->map[y][x - 1] == 'E'))
		map_test->e++;
	map_test->map[y][x] = '1';
	if (map_test->map[y - 1][x] && (map_test->map[y - 1][x] != '1'
		&& map_test->map[y - 1][x] != 'E'))
		map_tester(map_test, y - 1, x);
	if (map_test->map[y + 1][x] && (map_test->map[y +1][x] != '1'
		&& map_test->map[y +1][x] != 'E'))
		map_tester(map_test, y + 1, x);
	if (map_test->map[y][x - 1] && (map_test->map[y][x - 1] != '1'
		&& map_test->map[y][x - 1] != 'E'))
		map_tester(map_test, y, x - 1);
	if (map_test->map[y][x + 1] && (map_test->map[y][x + 1] != '1'
		&& map_test->map[y][x + 1] != 'E'))
		map_tester(map_test, y, x + 1);
}

int	verif_border(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != mlx->map.map_height)
	{
		while (mlx->map.map[i][j] != '\n' && mlx->map.map[i][j] != '\0')
		{
			if ((i == 0 && mlx->map.map[i][j] != '1')
					|| (i == mlx->map.map_height - 1
					&& mlx->map.map[i][j] != '1'))
				return (1);
			if ((j == 0 && mlx->map.map[i][j] != '1')
					|| (j == mlx->map.map_width - 1
					&& mlx->map.map[i][j] != '1'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	verif_elem_map(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	mlx->map.player = 0;
	while (i != mlx->map.map_height)
	{
		while (mlx->map.map[i][++j] != '\n' && mlx->map.map[i][j] != '\0')
		{
			if (mlx->map.map[i][j] == 'C')
				mlx->map.item++;
			if (mlx->map.map[i][j] == 'P')
				mlx->map.player++;
			if (mlx->map.map[i][j] == 'E')
				mlx->map.exit++;
			if (mlx->map.map[i][j] == 'e')
				mlx->map.ennemy++;
		}
		j = 0;
		i++;
	}
	if (mlx->map.item < 1 || mlx->map.player != 1 || mlx->map.exit != 1)
		return (1);
	return (0);
}

int	verif_map(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx->map.map_width = 0;
	while (i != mlx->map.map_height)
	{
		while (mlx->map.map[i][j])
		{
			j++;
		}
		if (i == mlx->map.map_height - 1)
			j++;
		if (mlx->map.map_width != 0 && j != mlx->map.map_width)
			return (1);
		mlx->map.map_width = j;
		j = 0;
		i++;
	}
	mlx->map.map_width--;
	return (0);
}

void	get_map(int fd, t_mlx_data *mlx, char **argv)
{
	int		i;
	char	*temp;

	i = 0;
	mlx->map.map_height = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(fd);
		mlx->map.map_height++;
	}
	close(fd);
	mlx->map.map = malloc(sizeof(char *) * (mlx->map.map_height + 1));
	fd = open(argv[1], O_RDONLY);
	while (i != mlx->map.map_height + 1)
	{
		mlx->map.map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}
