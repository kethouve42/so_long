/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:54:59 by kethouve          #+#    #+#             */
/*   Updated: 2024/02/22 13:41:42 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv_left(t_mlx_data *mlx)
{
	if (mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] == 'E'
			&& mlx->player.player_c == mlx->map.item)
	{
		on_destroy(mlx);
	}
	else if (mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] != '1'
		&& mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] == 'C')
		{
			mlx->map.map[mlx->player.player_y][mlx->player.player_x - 1] = '0';
			mlx->player.player_c++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_x--;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_r,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		ft_print("player move:");
		ft_putnbr(mlx->player.move);
		write(1, "\n", 1);
	}
}

void	mouv_right(t_mlx_data *mlx)
{
	if (mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] == 'E'
			&& mlx->player.player_c == mlx->map.item)
	{
		on_destroy(mlx);
	}
	else if (mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] != '1'
		&& mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] == 'C')
		{
			mlx->map.map[mlx->player.player_y][mlx->player.player_x + 1] = '0';
			mlx->player.player_c++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_x++;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_r,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		ft_print("player move:");
		ft_putnbr(mlx->player.move);
		write(1, "\n", 1);
	}
}

void	mouv_up(t_mlx_data *mlx)
{
	if (mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] == 'E'
			&& mlx->player.player_c == mlx->map.item)
	{
		on_destroy(mlx);
	}
	if (mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] != '1'
		&& mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] == 'C')
		{
			mlx->map.map[mlx->player.player_y - 1][mlx->player.player_x] = '0';
			mlx->player.player_c++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_y--;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_r,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		ft_print("player move:");
		ft_putnbr(mlx->player.move);
		write(1, "\n", 1);
	}
}

void	mouv_down(t_mlx_data *mlx)
{
	if (mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] == 'E'
			&& mlx->player.player_c == mlx->map.item)
	{
		on_destroy(mlx);
	}
	if (mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] != '1'
		&& mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] != 'E')
	{
		if (mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] == 'C')
		{
			mlx->map.map[mlx->player.player_y + 1][mlx->player.player_x] = '0';
			mlx->player.player_c++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_ground,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.player_y++;
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->image.img_player_r,
			mlx->player.player_x * 64, mlx->player.player_y * 64);
		mlx->player.move++;
		ft_print("player move:");
		ft_putnbr(mlx->player.move);
		write(1, "\n", 1);
	}
}
