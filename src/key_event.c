/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:56:27 by kethouve          #+#    #+#             */
/*   Updated: 2024/02/22 13:20:40 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	on_destroy(t_mlx_data *data)
{
	free_map(data->map.map);
	mlx_destroy_image(data->mlx, data->image.img_wall);
	mlx_destroy_image(data->mlx, data->image.img_ground);
	mlx_destroy_image(data->mlx, data->image.img_player_r);
	mlx_destroy_image(data->mlx, data->image.img_exit);
	mlx_destroy_image(data->mlx, data->image.img_item);
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
		mouv_left(mlx);
	if (keycode == 122)
		mouv_up(mlx);
	if (keycode == 115)
		mouv_down(mlx);
	if (keycode == 100)
		mouv_right(mlx);
	return (0);
}

int	on_keypress(int keysym, t_mlx_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}
