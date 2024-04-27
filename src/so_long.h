/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:32:04 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 17:53:55 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img_data
{
	int		img_height;
	int		img_width;
	void	*img_player_r;
	void	*img_ground;
	void	*img_wall;
	void	*img_exit;
	void	*img_item;
}	t_img_data;

typedef struct s_player_data
{
	int	player_x;
	int	player_y;
	int	player_c;
	int	move;
}	t_p_data;

typedef struct s_map_data
{
	char	**map;
	int		map_height;
	int		map_width;
	int		item;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;
}	t_map_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win_mlx;
	t_img_data	image;
	t_p_data	player;
	t_map_data	map;
}	t_mlx_data;

typedef struct s_tester
{
	char	**map;
	int		c;
	int		e;
}	t_tester;

int				main(int argc, char **argv);
int				verif_all(t_mlx_data *mlx);
int				verif_border(t_mlx_data *mlx);
int				verif_elem_map(t_mlx_data *mlx);
int				verif_map(t_mlx_data *mlx);
void			map_tester(t_tester *map_test, int y, int x);
void			get_map(int fd, t_mlx_data *mlx, char **argv);
void			display_image(t_mlx_data *data, int x, int y);
void			display_map(t_mlx_data *data, int y, int x);
int				on_destroy(t_mlx_data *data);
int				key_event(int keycode, t_mlx_data *mlx);
int				on_keypress(int keysym, t_mlx_data *data);
char			*get_next_line(int fd);
void			ft_putnbr(int nb);
void			ft_print(char *s);
void			mouv_left(t_mlx_data *mlx);
void			mouv_right(t_mlx_data *mlx);
void			mouv_up(t_mlx_data *mlx);
void			mouv_down(t_mlx_data *mlx);
void			load_image(void *mlx, t_img_data *image);
void			free_map(char **map);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);

#endif