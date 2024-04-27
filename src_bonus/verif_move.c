/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:42:42 by kethouve          #+#    #+#             */
/*   Updated: 2024/03/08 16:27:54 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			if (e < e2 && next_verif(mlx, y, x, e2) == 1)
				return (1);
		}
		e2++;
		if (e2 == e)
			e2++;
	}
	return (0);
}

int	next_verif(t_mlx_data *mlx, int y, int x, int e)
{
	int	e2;
	int	h;
	int	w;

	e2 = e + 1;
	h = mlx->ennemy[e].e_y + y;
	w = mlx->ennemy[e].e_x + x;
	if (mlx->map.map[h][w] == '1'
		|| mlx->map.map[h][w] == 'E'
		|| mlx->map.map[h][w] == 'C')
		return (1);
	while (e2 < mlx->map.ennemy)
	{
		if (mlx->ennemy[e].e_y + y == mlx->ennemy[e2].e_y
			&& mlx->ennemy[e].e_x + x == mlx->ennemy[e2].e_x)
		{
			if (next_verif(mlx, y, x, e2) == 1)
				return (1);
		}
		e2++;
	}
	return (0);
}
