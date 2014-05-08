/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:13:16 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:44:27 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		up(t_alpha *m)
{
	if (m->worldmap[(int)(m->posx + m->dirx * 0.3)][(int)(m->posy)] == 0)
		m->posx += m->dirx * 0.3;
	if (m->worldmap[(int)(m->posx)][(int)(m->posy + m->diry * 0.3)] == 0)
		m->posy += m->diry * 0.3;
	calc(m);
}

void		down(t_alpha *m)
{
	if (m->worldmap[(int)(m->posx - m->dirx * 0.3)][(int)(m->posy)] == 0)
		m->posx -= m->dirx * 0.3;
	if (m->worldmap[(int)(m->posx)][(int)(m->posy - m->diry * 0.3)] == 0)
		m->posy -= m->diry * 0.3;
	calc(m);
}

void		right(t_alpha *m, double rotspeed)
{
	double		olddirx;
	double		oldplanex;

	olddirx = m->dirx;
	oldplanex = m->planx;
	m->dirx = m->dirx * cos(-rotspeed) - m->diry * sin(-rotspeed);
	m->diry = olddirx * sin(-rotspeed) + m->diry * cos(-rotspeed);
	m->planx = m->planx * cos(-rotspeed) - m->plany * sin(-rotspeed);
	m->plany = oldplanex * sin(-rotspeed) + m->plany * cos(-rotspeed);
	calc(m);
}

void		left(t_alpha *m, double rotspeed)
{
	double		olddirx;
	double		oldplanex;

	olddirx = m->dirx;
	oldplanex = m->planx;
	m->dirx = m->dirx * cos(rotspeed) - m->diry * sin(rotspeed);
	m->diry = olddirx * sin(rotspeed) + m->diry * cos(rotspeed);
	m->planx = m->planx * cos(rotspeed) - m->plany * sin(rotspeed);
	m->plany = oldplanex * sin(rotspeed) + m->plany * cos(rotspeed);
	calc(m);
}
