/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:54:55 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 18:07:27 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(void *mlx, t_img_data *image)
{
	image->img_height = 64;
	image->img_width = 64;
	image->img_wall = mlx_xpm_file_to_image(mlx, "./rscs/mur.xpm",
			&(image->img_width), &(image->img_height));
	image->img_item = mlx_xpm_file_to_image(mlx, "./rscs/item.xpm",
			&(image->img_width), &(image->img_height));
	image->img_ground = mlx_xpm_file_to_image(mlx, "./rscs/sol.xpm",
			&(image->img_width), &(image->img_height));
	image->img_player_r = mlx_xpm_file_to_image(mlx, "./rscs/player_r.xpm",
			&(image->img_width), &(image->img_height));
	image->img_exit = mlx_xpm_file_to_image(mlx, "./rscs/exit.xpm",
			&(image->img_width), &(image->img_height));
}

void	display_map(t_mlx_data *mlx, int y, int x)
{
	while (++y < mlx->map.map_height)
	{
		x = -1;
		while (++x < mlx->map.map_width)
		{
			if (mlx->map.map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_wall, x * 64, y * 64);
			else if (mlx->map.map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_ground, x * 64, y * 64);
			else if (mlx->map.map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_item, x * 64, y * 64);
			else if (mlx->map.map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_player_r, x * 64, y * 64);
			else if (mlx->map.map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_exit, x * 64, y * 64);
		}
	}
}
