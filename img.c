/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:04:54 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:41:35 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color(t_alpha *mlx)
{
	if (mlx->tmp == L)
		mlx->color = COLORA;
	if (mlx->tmp == R)
		mlx->color = COLORB;
	if (mlx->tmp == D)
		mlx->color = COLORC;
	if (mlx->tmp == U)
		mlx->color = COLORD;
}

void		set_color(char *data, int color)
{
	data[0] = color & 0xff;
	data[1] = (color >> 8) & 0xff;
	data[2] = (color >> 16) & 0xff;
}

t_alpha		*ft_trace_line(t_alpha *m, int x)
{
	int		i;

	color(m);
	m->dat = mlx_get_data_addr(m->img, &(m->bpp), &(m->sizel), &(m->endian));
	i = m->drawstart - 1;
	while (++i <= m->drawend)
	{
		set_color(m->dat + (x * (m->bpp / 8) + (i * m->sizel)), m->color);
	}
	return (m);
}

void		background(t_alpha *m, double w, double h)
{
	int		x;
	int		i;
	int		pos;

	m->dat = mlx_get_data_addr(m->img, &(m->bpp), &(m->sizel), &(m->endian));
	x = 0;
	while (x < w)
	{
		i = -1;
		while (++i < h)
		{
			pos = x * (m->bpp / 8) + (i * m->sizel);
			if (i < (h / 2))
				set_color(m->dat + pos, 0x003366);
			else
				set_color(m->dat + pos, 0xbbae98);
		}
		x++;
	}
}
