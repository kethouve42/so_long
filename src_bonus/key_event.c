/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:56:27 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/11 13:21:56 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_counter(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->image.img_00);
	mlx_destroy_image(data->mlx, data->image.img_01);
	mlx_destroy_image(data->mlx, data->image.img_02);
	mlx_destroy_image(data->mlx, data->image.img_03);
	mlx_destroy_image(data->mlx, data->image.img_04);
	mlx_destroy_image(data->mlx, data->image.img_05);
	mlx_destroy_image(data->mlx, data->image.img_06);
	mlx_destroy_image(data->mlx, data->image.img_07);
	mlx_destroy_image(data->mlx, data->image.img_08);
	mlx_destroy_image(data->mlx, data->image.img_09);
}

int	on_destroy(t_mlx_data *data)
{
	free_map(data->map.map);
	mlx_destroy_image(data->mlx, data->image.img_wall);
	mlx_destroy_image(data->mlx, data->image.img_ground);
	mlx_destroy_image(data->mlx, data->image.img_player_r);
	mlx_destroy_image(data->mlx, data->image.img_player_l);
	mlx_destroy_image(data->mlx, data->image.img_player_u);
	mlx_destroy_image(data->mlx, data->image.img_player_d);
	mlx_destroy_image(data->mlx, data->image.img_exit);
	mlx_destroy_image(data->mlx, data->image.img_exit_2);
	mlx_destroy_image(data->mlx, data->image.img_item);
	mlx_destroy_image(data->mlx, data->image.img_e_r);
	mlx_destroy_image(data->mlx, data->image.img_e_l);
	mlx_destroy_image(data->mlx, data->image.img_e_u);
	mlx_destroy_image(data->mlx, data->image.img_e_d);
	destroy_counter(data);
	mlx_destroy_window(data->mlx, data->win_mlx);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	key_event(int keycode, t_mlx_data *mlx)
{
	if (keycode == 65307)
		on_destroy(mlx);
	if (keycode == 113)
	{
		mouv_left(mlx);
		mouv_ennemy_left(mlx, 0);    // Modifié les touche en qwerty
	}
	if (keycode == 122)
	{
		mouv_up(mlx);
		mouv_ennemy_up(mlx, 0);
	}
	if (keycode == 115)
	{
		mouv_down(mlx);
		mouv_ennemy_down(mlx, 0);
	}
	if (keycode == 100)
	{
		mouv_right(mlx);
		mouv_ennemy_right(mlx, 0);
	}
	return (0);
}

int	on_keypress(int keysym, t_mlx_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}
