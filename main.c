/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:12:30 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:41:30 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

static t_alpha		*init_alpha(void)
{
	t_alpha		*m;

	m = (t_alpha *)malloc(sizeof(t_alpha));
	if (!m)
		exit(0);
	m->posx = 17;
	m->posy = 12;
	m->dirx = -1;
	m->diry = 0;
	m->planx = 0;
	m->plany = 0.66;
	map(m);
	return (m);
}

int					main(void)
{
	t_alpha		*m;

	m = init_alpha();
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 1500, 850, "wolf_3D");
	m->img = mlx_new_image(m->mlx, 1500, 850);
	mlx_hook(m->win, 2, (1L << 0), &key_hook, m);
	mlx_loop_hook(m->mlx, expose_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
