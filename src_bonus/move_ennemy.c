/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:32:10 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 16:28:52 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mouv_ennemy_left(t_mlx_data *mlx, int e)
{
	while (e != mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y == mlx->player.player_y
			&& mlx->ennemy[e].e_x - 1 == mlx->player.player_x)
			on_destroy(mlx);
		else if (mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x - 1] != '1'
			&& mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x - 1] != 'E'
			&& mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x - 1] != 'C'
			&& verif_between_ennemy(mlx, e, 0, -1) == 0)
		{
			mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x] = '0';
			if (verif_between_ennemy(mlx, e, 0, 0) == 0
				&& (mlx->ennemy[e].e_y != mlx->player.player_y
					|| mlx->ennemy[e].e_x != mlx->player.player_x))
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_ground, mlx->ennemy[e].e_x * 64,
					mlx->ennemy[e].e_y * 64);
			mlx->ennemy[e].e_x--;
			mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_e_l,
				mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
		}
		e++;
	}
}

void	mouv_ennemy_right(t_mlx_data *mlx, int e)
{
	while (e != mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y == mlx->player.player_y
			&& mlx->ennemy[e].e_x + 1 == mlx->player.player_x)
			on_destroy(mlx);
		else if (mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x + 1] != '1'
			&& mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x + 1] != 'E'
			&& mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x + 1] != 'C'
			&& verif_between_ennemy(mlx, e, 0, 1) == 0)
		{
			mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x] = '0';
			if (verif_between_ennemy(mlx, e, 0, 0) == 0
				&& (mlx->ennemy[e].e_y != mlx->player.player_y
					|| mlx->ennemy[e].e_x != mlx->player.player_x))
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_ground,
					mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
			mlx->ennemy[e].e_x++;
			mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_e_r,
				mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
		}
		e++;
	}
}

void	mouv_ennemy_up(t_mlx_data *mlx, int e)
{
	while (e != mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y - 1 == mlx->player.player_y
			&& mlx->ennemy[e].e_x == mlx->player.player_x)
			on_destroy(mlx);
		else if (mlx->map.map[mlx->ennemy[e].e_y - 1][mlx->ennemy[e].e_x] != '1'
			&& mlx->map.map[mlx->ennemy[e].e_y - 1][mlx->ennemy[e].e_x] != 'E'
			&& mlx->map.map[mlx->ennemy[e].e_y - 1][mlx->ennemy[e].e_x] != 'C'
			&& verif_between_ennemy(mlx, e, -1, 0) == 0)
		{
			mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x] = '0';
			if (verif_between_ennemy(mlx, e, 0, 0) == 0
				&& (mlx->ennemy[e].e_y != mlx->player.player_y
					|| mlx->ennemy[e].e_x != mlx->player.player_x))
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_ground,
					mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
			mlx->ennemy[e].e_y--;
			mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_e_u,
				mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
		}
		e++;
	}
}

void	mouv_ennemy_down(t_mlx_data *mlx, int e)
{
	while (e != mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y + 1 == mlx->player.player_y
			&& mlx->ennemy[e].e_x == mlx->player.player_x)
			on_destroy(mlx);
		else if (mlx->map.map[mlx->ennemy[e].e_y + 1][mlx->ennemy[e].e_x] != '1'
			&& mlx->map.map[mlx->ennemy[e].e_y + 1][mlx->ennemy[e].e_x] != 'E'
			&& mlx->map.map[mlx->ennemy[e].e_y + 1][mlx->ennemy[e].e_x] != 'C'
			&& verif_between_ennemy(mlx, e, 1, 0) == 0)
		{
			mlx->map.map[mlx->ennemy[e].e_y][mlx->ennemy[e].e_x] = '0';
			if (verif_between_ennemy(mlx, e, 0, 0) == 0
				&& (mlx->ennemy[e].e_y != mlx->player.player_y
					|| mlx->ennemy[e].e_x != mlx->player.player_x))
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_ground,
					mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
			mlx->ennemy[e].e_y++;
			mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_e_d,
				mlx->ennemy[e].e_x * 64, mlx->ennemy[e].e_y * 64);
		}
		e++;
	}
}
/*
int	verif_between_ennemy(t_mlx_data *mlx, int e, int y, int x)
{
	int	e2;

	e2 = 0;
	if (e == 0)
		e2++;
	while (e2 < mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y + y == mlx->ennemy[e2].e_y
			&& mlx->ennemy[e].e_x + x == mlx->ennemy[e2].e_x)
		{
			if (e > e2)
				return (1);
			if (e < e2
				&& (mlx->map.map[mlx->ennemy[e].e_y + y * 2]
					[mlx->ennemy[e].e_x + x * 2] == '1'
					|| mlx->map.map[mlx->ennemy[e].e_y + y * 2]
					[mlx->ennemy[e].e_x + x * 2] == 'E'
					|| mlx->map.map[mlx->ennemy[e].e_y + y * 2]
					[mlx->ennemy[e].e_x + x * 2] == 'C'))
				return (1);
		}
		e2++;
		if (e2 == e)
			e2++;
	}
	return (0);
}*/
