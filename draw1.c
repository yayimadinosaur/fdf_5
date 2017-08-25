/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:17:11 by wfung             #+#    #+#             */
/*   Updated: 2017/08/24 16:28:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
static void		draw_gradual(t_env *e, float fixed_pt, float next)
{

}

static void		draw_sharp(t_env *e, float fixed_pt, float next)
{

}
*/

static void		draw_straight(t_env *e, float fixed_pt, float next, int dir)
{
	if (dir == 0)
		mlx_pixel_put(e->mlx, e->win, next, fixed_pt, 0xff00);	//green
	else if (dir == 1)
		mlx_pixel_put(e->mlx, e->win, fixed_pt, next, 0xff0000);	//red
}

static void		draw_right(t_env *e)
{
	int		i;
	int		j;
	float	next;

	i = 0;
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			next = e->pts[i][j].x;
			while (j + 1 < e->col && next <= e->pts[i][j + 1].x)
			{
			/*	if ((e->pts[i][j].m > 0 && e->pts[i][j].m < 1)
						|| (e->pts[i][j].m > -1 && e->pts[i][j].m < 0))
					draw_gradual(e, next);
				else if (e->pts[i][j].m < -1 || e->pts[i][j].m > 1)
					draw_sharp(e, next);
				else	//m == 0
			*/	if (e->pts[i][j].m == 0)	
					draw_straight(e, e->pts[i][j].y, next, 0);
				next++;
			}
			j++;
		}
		i++;
	}
}

static void		draw_down(t_env *e)
{
	int		i;
	int		j;
	float	next;

	i = 0;
	while (i < e->row - 1)
	{
		j = 0;
		while (j < e->col)
		{
			next = e->pts[i][j].y;
			while (next <= e->pts[i + 1][j].y)
			{
			//	printf("i = %i j = %i next = [%f] cmp = [%f]\n", i, j, next, e->pts[i][j].y);
	/*		if ((e->pts[i][j].m > 0 && e->pts[i][j].m < 1)
					|| (e->pts[i][j].m > -1 && e->pts[i][j].m < 0))
				draw_gradual(next);
			else if (e->pts[i][j].m < -1 || e->pts[i][j].m > 1)
				draw_sharp(e, next);
			else	//m == 0
	*/			if (e->pts[i][j].m == 0)
					draw_straight(e, e->pts[i][j].x, next, 1);
				next++;
			}
			j++;
		}
		i++;
	}
}

void			draw1(t_env *e)
{
	draw_right(e);
	draw_down(e);
}
