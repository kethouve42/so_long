/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:55:46 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/06 16:10:04 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**dup_map(char **tab)
{
	char	**out;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	out = malloc((i + 1) * sizeof(char *));
	i = -1;
	while (tab[++i])
		out[i] = ft_strdup(tab[i]);
	out[i] = NULL;
	return (out);
}

void	get_pos(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != mlx->map.map_height)
	{
		while (mlx->map.map[i][j] != '\n' && mlx->map.map[i][j] != '\0')
		{
			if (mlx->map.map[i][j] == 'P')
			{
				mlx->player.player_x = j;
				mlx->player.player_y = i;
			}
			if (mlx->map.map[i][j] == 'E')
			{
				mlx->map.exit_x = j;
				mlx->map.exit_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	verif_all(t_mlx_data *mlx)
{
	t_tester	*map_test;

	map_test = malloc(sizeof(t_tester));
	map_test->map = dup_map(mlx->map.map);
	map_test->c = 0;
	map_test->e = 0;
	if (mlx->map.map_height < 3)
		return (free_map(map_test->map), free(map_test), 1);
	if (verif_map(mlx) == 1)
		return (free_map(map_test->map), free(map_test), 1);
	if (verif_elem_map(mlx) == 1)
		return (free_map(map_test->map), free(map_test), 1);
	if (verif_border(mlx) == 1)
		return (free_map(map_test->map), free(map_test), 1);
	if (!mlx->map.map)
		return (free_map(map_test->map), free(map_test), 1);
	map_tester(map_test, mlx->player.player_y, mlx->player.player_x);
	if (map_test->c != mlx->map.item || map_test->e != 1)
		return (free_map(map_test->map), free(map_test), 1);
	free_map(map_test->map);
	free(map_test);
	return (0);
}

void	game(t_mlx_data *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return ;
	load_image(mlx->mlx, &(mlx->image));
	load_img_ennemy(mlx->mlx, &(mlx->image));
	load_img_count(mlx->mlx, &(mlx->image));
	mlx->win_mlx = mlx_new_window(mlx->mlx, (mlx->map.map_width * 64) - 1,
			(mlx->map.map_height * 64) - 1, "So_long");
	if (!mlx->win_mlx)
		return (free(mlx->mlx));
	display_map(mlx, -1, -1);
	mlx_key_hook(mlx->win_mlx, &key_event, mlx);
	mlx_hook(mlx->win_mlx, 17, 0L, &on_destroy, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx;
	int			fd;

	if (argc != 2)
		return (write(1, "error enter so_long (map).ber\n", 30), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (write(1, "fd error\n", 9), 1);
	mlx = malloc(sizeof(t_mlx_data));
	mlx->player.player_y = 0;
	mlx->player.player_x = 0;
	mlx->map.exit_x = 0;
	mlx->map.exit_y = 0;
	mlx->player.move = 0;
	mlx->player.player_c = 0;
	mlx->map.item = 0;
	mlx->map.exit = 0;
	mlx->map.ennemy = 0;
	get_map(fd, mlx, argv);
	get_pos(mlx);
	if (verif_all(mlx) == 1)
		return (free_map(mlx->map.map), free(mlx),
			write(1, "map invalid\n", 12), 1);
	game(mlx);
}
