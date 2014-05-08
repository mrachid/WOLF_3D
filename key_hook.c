/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:12:19 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:39:55 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		expose_hook(t_alpha *m)
{
	calc(m);
	return (0);
}

int		key_hook(int keycode, t_alpha *mlx)
{
	double		rotspeed;

	rotspeed = 0.15;
	if (keycode == 65362)
		up(mlx);
	if (keycode == 65364)
		down(mlx);
	if (keycode == 65363)
		right(mlx, rotspeed);
	if (keycode == 65361)
		left(mlx, rotspeed);
	if (keycode == 65307)
		exit(0);
	return (0);
}
