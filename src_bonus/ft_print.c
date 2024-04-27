/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:48:10 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/01 17:49:22 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	scoreboard_2(int nb, t_mlx_data *mlx, int y, int x)
{
	if (nb == '6')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_06, x * 64, y * 64);
	if (nb == '7')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_07, x * 64, y * 64);
	if (nb == '8')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_08, x * 64, y * 64);
	if (nb == '9')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_09, x * 64, y * 64);
}

void	scoreboard(int nb, t_mlx_data *mlx, int y, int x)
{
	if (nb == '0')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_00, x * 64, y * 64);
	if (nb == '1')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_01, x * 64, y * 64);
	if (nb == '2')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_02, x * 64, y * 64);
	if (nb == '3')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_03, x * 64, y * 64);
	if (nb == '4')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_04, x * 64, y * 64);
	if (nb == '5')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_05, x * 64, y * 64);
	scoreboard_2(nb, mlx, y, x);
}

void	print_move(int nb, t_mlx_data *mlx)
{
	char	*dest;
	int		i;
	int		x;

	x = 0;
	if (mlx == NULL)
		return ;
	dest = ft_itoa(nb);
	i = ft_strlen(dest);
	while (x != i)
	{
		scoreboard(dest[x], mlx, 0, x);
		x++;
	}
	free(dest);
}

void	ft_print(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
