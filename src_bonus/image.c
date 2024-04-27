/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:54:55 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 18:09:16 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_img_count(void *mlx, t_img_data *image)
{
	image->img_01 = mlx_xpm_file_to_image(mlx, "./rscs/01.xpm",
			&image->img_width, &image->img_height);
	image->img_02 = mlx_xpm_file_to_image(mlx, "./rscs/02.xpm",
			&image->img_width, &image->img_height);
	image->img_03 = mlx_xpm_file_to_image(mlx, "./rscs/03.xpm",
			&image->img_width, &image->img_height);
	image->img_04 = mlx_xpm_file_to_image(mlx, "./rscs/04.xpm",
			&image->img_width, &image->img_height);
	image->img_05 = mlx_xpm_file_to_image(mlx, "./rscs/05.xpm",
			&image->img_width, &image->img_height);
	image->img_06 = mlx_xpm_file_to_image(mlx, "./rscs/06.xpm",
			&image->img_width, &image->img_height);
	image->img_07 = mlx_xpm_file_to_image(mlx, "./rscs/07.xpm",
			&image->img_width, &image->img_height);
	image->img_08 = mlx_xpm_file_to_image(mlx, "./rscs/08.xpm",
			&image->img_width, &image->img_height);
	image->img_09 = mlx_xpm_file_to_image(mlx, "./rscs/09.xpm",
			&image->img_width, &image->img_height);
	image->img_00 = mlx_xpm_file_to_image(mlx, "./rscs/00.xpm",
			&image->img_width, &image->img_height);
}

void	load_img_ennemy(void *mlx, t_img_data *image)
{
	image->img_e_r = mlx_xpm_file_to_image(mlx, "./rscs/ennemy_r.xpm",
			&image->img_width, &image->img_height);
	image->img_e_l = mlx_xpm_file_to_image(mlx, "./rscs/ennemy_l.xpm",
			&image->img_width, &image->img_height);
	image->img_e_u = mlx_xpm_file_to_image(mlx, "./rscs/ennemy_u.xpm",
			&image->img_width, &image->img_height);
	image->img_e_d = mlx_xpm_file_to_image(mlx, "./rscs/ennemy_d.xpm",
			&image->img_width, &image->img_height);
}

void	load_image(void *mlx, t_img_data *image)
{
	image->img_height = 64;
	image->img_width = 64;
	image->img_wall = mlx_xpm_file_to_image(mlx, "./rscs/mur.xpm",
			&image->img_width, &image->img_height);
	image->img_item = mlx_xpm_file_to_image(mlx, "./rscs/item.xpm",
			&image->img_width, &image->img_height);
	image->img_ground = mlx_xpm_file_to_image(mlx, "./rscs/sol.xpm",
			&image->img_width, &image->img_height);
	image->img_player_r = mlx_xpm_file_to_image(mlx, "./rscs/player_r.xpm",
			&image->img_width, &image->img_height);
	image->img_player_l = mlx_xpm_file_to_image(mlx, "./rscs/player_l.xpm",
			&image->img_width, &image->img_height);
	image->img_player_d = mlx_xpm_file_to_image(mlx, "./rscs/player_d.xpm",
			&image->img_width, &image->img_height);
	image->img_player_u = mlx_xpm_file_to_image(mlx, "./rscs/player_u.xpm",
			&image->img_width, &image->img_height);
	image->img_exit = mlx_xpm_file_to_image(mlx, "./rscs/exit.xpm",
			&image->img_width, &image->img_height);
	image->img_exit_2 = mlx_xpm_file_to_image(mlx, "./rscs/exit2.xpm",
			&image->img_width, &image->img_height);
}

void	display_map(t_mlx_data *mlx, int y, int x)
{
	int	e;

	e = 0;
	while (++y < mlx->map.map_height)
	{
		x = -1;
		if (y == 0)
		{
			x++;
			mlx_put_image_to_window(mlx->mlx,
				mlx->win_mlx, mlx->image.img_00, x * 64, y * 64);
		}
		while (++x < mlx->map.map_width)
		{
			if (mlx->map.map[y][x] == 'e')
			{
				mlx_put_image_to_window(mlx->mlx,
					mlx->win_mlx, mlx->image.img_e_r, x * 64, y * 64);
				mlx->ennemy[e].e_y = y;
				mlx->ennemy[e].e_x = x;
				e++;
			}
			display_map2(mlx, y, x);
		}
	}
}

void	display_map2(t_mlx_data *mlx, int y, int x)
{
	if (mlx->map.map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_wall, x * 64, y * 64);
	else if (mlx->map.map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_item, x * 64, y * 64);
	else if (mlx->map.map[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_ground, x * 64, y * 64);
	else if (mlx->map.map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_player_r, x * 64, y * 64);
	else if (mlx->map.map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx,
			mlx->win_mlx, mlx->image.img_exit, x * 64, y * 64);
}
