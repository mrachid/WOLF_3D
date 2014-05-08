/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:13:00 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:44:20 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_alpha			*ft_init(t_alpha *mlx, int x, double w)
{
	mlx->camx = 2 * x / w - 1;
	mlx->rpx = mlx->posx;
	mlx->rpy = mlx->posy;
	mlx->rdx = mlx->dirx + mlx->planx * mlx->camx;
	mlx->rdy = mlx->diry + mlx->plany * mlx->camx;
	mlx->mapx = (int)(mlx->rpx);
	mlx->mapy = (int)(mlx->rpy);
	mlx->ddx = sqrt(1 + (mlx->rdy * mlx->rdy) / (mlx->rdx * mlx->rdx));
	mlx->ddy = sqrt(1 + (mlx->rdx * mlx->rdx) / (mlx->rdy * mlx->rdy));
	mlx->hit = 0;
	return (mlx);
}

t_alpha			*ft_line(t_alpha *mlx)
{
	if (mlx->rdx < 0)
	{
		mlx->sx = -1;
		mlx->sdx = (mlx->rpx - mlx->mapx) * mlx->ddx;
	}
	else
	{
		mlx->sx = 1;
		mlx->sdx = (mlx->mapx + 1.0 - mlx->rpx) * mlx->ddx;
	}
	if (mlx->rdy < 0)
	{
		mlx->sy = -1;
		mlx->sdy = (mlx->rpy - mlx->mapy) * mlx->ddy;
	}
	else
	{
		mlx->sy = 1;
		mlx->sdy = (mlx->mapy + 1.0 - mlx->rpy) * mlx->ddy;
	}
	return (mlx);
}
