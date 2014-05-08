/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:13:37 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/01 17:43:41 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define MAPW 46
# define MAPH 38

# define R 0
# define L 1
# define U 2
# define D 3

# define COLORA 0x999999
# define COLORB 0xdddddd
# define COLORC 0x56739a
# define COLORD 0x666666

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>

typedef struct			s_map
{
	int					y;
	int					x;
	int					**map;
}						t_map;

typedef struct			s_alpha
{
	double				camx;
	double				ddx;
	double				ddy;
	double				sdx;
	double				sdy;
	double				rdx;
	double				rdy;
	double				rpx;
	double				rpy;
	int					sx;
	int					sy;
	int					side;
	int					mapx;
	int					mapy;
	int					hit;
	void				*mlx;
	void				*win;
	double				dirx;
	double				diry;
	double				planx;
	double				plany;
	double				posx;
	double				posy;
	int					x;
	int					lineh;
	double				pwd;
	int					drawstart;
	int					drawend;
	int					endian;
	int					sizel;
	int					bpp;
	void				*img;
	char				*dat;
	int					color;
	int					worldmap[MAPH][MAPW];
	int					tmp;
	int					test;
}						t_alpha;
void					color(t_alpha *mlx);
void					map(t_alpha *m);
int						expose_hook(t_alpha *m);
void					set_color(char *data, int color);
void					background(t_alpha *m, double w, double h);
t_alpha					*ft_line(t_alpha *mlx);
t_alpha					*ft_init(t_alpha *mlx, int x, double w);
t_alpha					*ft_trace_line(t_alpha *m, int x);
int						key_hook(int keycode, t_alpha *mlx);
void					move(int keycode, t_alpha *mlx);
void					calc(t_alpha *mlx);
void					up(t_alpha *m);
void					down(t_alpha *m);
void					right(t_alpha *m, double rotspeed);
void					left(t_alpha *m, double rotspeed);
#endif
