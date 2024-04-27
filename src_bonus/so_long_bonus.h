/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:32:04 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 18:01:41 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*img_player_l;
	void	*img_player_u;
	void	*img_player_d;
	void	*img_ground;
	void	*img_wall;
	void	*img_exit;
	void	*img_exit_2;
	void	*img_item;
	void	*img_e_r;
	void	*img_e_l;
	void	*img_e_u;
	void	*img_e_d;
	void	*img_00;
	void	*img_01;
	void	*img_02;
	void	*img_03;
	void	*img_04;
	void	*img_05;
	void	*img_06;
	void	*img_07;
	void	*img_08;
	void	*img_09;
}	t_img_data;

typedef struct s_player_data
{
	int	player_x;
	int	player_y;
	int	player_c;
	int	move;
}	t_p_data;

typedef struct s_ennemy_data
{
	int	e_x;
	int	e_y;
}	t_e_data;

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
	int		ennemy;
}	t_map_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win_mlx;
	t_img_data	image;
	t_p_data	player;
	t_map_data	map;
	t_e_data	ennemy[100];
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
void			display_map2(t_mlx_data *mlx, int y, int x);
int				on_destroy(t_mlx_data *data);
int				key_event(int keycode, t_mlx_data *mlx);
int				on_keypress(int keysym, t_mlx_data *data);
char			*get_next_line(int fd);
void			ft_putnbr(int nb, t_mlx_data *mlx, int x);
void			scoreboard(int nb, t_mlx_data *mlx, int y, int x);
void			scoreboard_2(int nb, t_mlx_data *mlx, int y, int x);
void			ft_print(char *s);
void			mouv_left(t_mlx_data *mlx);
void			mouv_right(t_mlx_data *mlx);
void			mouv_up(t_mlx_data *mlx);
void			mouv_down(t_mlx_data *mlx);
void			load_image(void *mlx, t_img_data *image);
void			load_img_ennemy(void *mlx, t_img_data *image);
void			load_img_count(void *mlx, t_img_data *image);
void			free_map(char **map);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
void			print_move(int nb, t_mlx_data *mlx);
char			*ft_itoa(int n);
int				count_digit(int n);
void			ft_putitoa(char *dest, int n, int ndigit);
void			ft_bzero(void *s, size_t n);
void			mouv_ennemy_left(t_mlx_data *mlx, int e);
void			mouv_ennemy_right(t_mlx_data *mlx, int e);
void			mouv_ennemy_up(t_mlx_data *mlx, int e);
void			mouv_ennemy_down(t_mlx_data *mlx, int e);
int				verif_ennemy(t_mlx_data *mlx, int y, int x);
int				verif_between_ennemy(t_mlx_data *mlx, int e, int y, int x);
int 			next_verif(t_mlx_data *mlx, int y, int x, int e);

#endif