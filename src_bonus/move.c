/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:54:59 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/01 17:45:41 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mouv_left(t_mlx_data *mlx)
{
	if ((mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] == 'E'
		&& mlx->player.player_c == mlx->map.item)
		|| verif_ennemy(mlx, 0, -1) == 1)
		on_destroy(mlx);
	else if (mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] != '1'
		&& mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] == 'C')
		{
			mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] = '0';
			mlx->player.player_c++;
			if (mlx->player.player_c == mlx->map.item)
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_exit_2,
					mlx->map.exit_x * 64, mlx->map.exit_y * 64);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_x--;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_l,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		print_move(mlx->player.move, mlx);
	}
}

void	mouv_right(t_mlx_data *mlx)
{
	if ((mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] == 'E'
		&& mlx->player.player_c == mlx->map.item)
		|| verif_ennemy(mlx, 0, 1) == 1)
		on_destroy(mlx);
	else if (mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] != '1'
		&& mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] == 'C')
		{
			mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] = '0';
			mlx->player.player_c++;
			if (mlx->player.player_c == mlx->map.item)
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_exit_2, mlx->map.exit_x * 64,
					mlx->map.exit_y * 64);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_x++;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_r,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		print_move(mlx->player.move, mlx);
	}
}

void	mouv_up(t_mlx_data *mlx)
{
	if ((mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] == 'E'
		&& mlx->player.player_c == mlx->map.item)
		|| verif_ennemy(mlx, -1, 0) == 1)
		on_destroy(mlx);
	else if (mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] != '1'
		&& mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] == 'C')
		{
			mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] = '0';
			mlx->player.player_c++;
			if (mlx->player.player_c == mlx->map.item)
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_exit_2, mlx->map.exit_x * 64,
					mlx->map.exit_y * 64);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_y--;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_u,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		print_move(mlx->player.move, mlx);
	}
}

void	mouv_down(t_mlx_data *mlx)
{
	if ((mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] == 'E'
		&& mlx->player.player_c == mlx->map.item)
		|| verif_ennemy(mlx, 1, 0) == 1)
		on_destroy(mlx);
	else if (mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] != '1'
		&& mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] == 'C')
		{
			mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] = '0';
			mlx->player.player_c++;
			if (mlx->player.player_c == mlx->map.item)
				mlx_put_image_to_window(mlx->mlx, mlx->win_mlx,
					mlx->image.img_exit_2, mlx->map.exit_x * 64,
					mlx->map.exit_y * 64);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_y++;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_d,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		print_move(mlx->player.move, mlx);
	}
}

int	verif_ennemy(t_mlx_data *mlx, int y, int x)
{
	int	e;

	e = 0;
	while (e != mlx->map.ennemy)
	{
		if (mlx->player.player_y + y == mlx->ennemy[e].e_y
			&& mlx->player.player_x + x == mlx->ennemy[e].e_x)
			return (1);
		e++;
	}
	return (0);
}
