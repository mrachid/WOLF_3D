/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hearts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:12:06 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 18:17:46 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void				copymap(t_alpha *m, int worldmap[MAPH][MAPW])
{
	int					pos[2];

	pos[0] = -1;
	while (++(pos[0]) < MAPH)
	{
		pos[1] = -1;
		while (++(pos[1]) < MAPW)
			m->worldmap[pos[0]][pos[1]] = worldmap[pos[0]][pos[1]];
	}
}

void					map(t_alpha *m)
{
	static int			worldmap[MAPH][MAPW] =

	{
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 2},
	{2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 2},
	{2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 2},
	{2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 2},
	{2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 2},
	{2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 2},
	{2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 2},
	{2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 2},
	{2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	};
	copymap(m, worldmap);
}

static t_alpha			*vbl_trace(t_alpha *mlx, double h)
{
	if (mlx->side == 0)
		mlx->pwd = fabs((mlx->mapx - mlx->rpx + (1 - mlx->sx) / 2) / mlx->rdx);
	else
		mlx->pwd = fabs((mlx->mapy - mlx->rpy + (1 - mlx->sy) / 2) / mlx->rdy);
	mlx->lineh = abs((int)(h / mlx->pwd));
	mlx->drawstart = -mlx->lineh / 2 + h / 2;
	if (mlx->drawstart < 0)
		mlx->drawstart = 0;
	mlx->drawend = mlx->lineh / 2 + h / 2;
	if (mlx->drawend >= h)
		mlx->drawend = h - 1;
	return (mlx);
}

static t_alpha			*ft_jump(t_alpha *mlx)
{
	while (mlx->hit == 0 && mlx->mapx < MAPW && mlx->mapy < MAPH)
	{
		if (mlx->sdx < mlx->sdy)
		{
			mlx->sdx += mlx->ddx;
			mlx->mapx += mlx->sx;
			mlx->side = 0;
			mlx->tmp = L;
			if (mlx->sx == -1)
				mlx->tmp = R;
		}
		else
		{
			mlx->sdy += mlx->ddy;
			mlx->mapy += mlx->sy;
			mlx->side = 1;
			mlx->tmp = D;
			if (mlx->sy == -1)
				mlx->tmp = U;
		}
		mlx->hit = (mlx->worldmap)[mlx->mapx][mlx->mapy] > 0 ? 1 : 0;
	}
	return (mlx);
}

void					calc(t_alpha *mlx)
{
	double		w;
	double		h;
	int			x;

	x = -1;
	w = 1500;
	h = 850;
	background(mlx, w, h);
	while (x++ < w)
	{
		ft_init(mlx, x, w);
		ft_line(mlx);
		ft_jump(mlx);
		vbl_trace(mlx, h);
		ft_trace_line(mlx, x);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
