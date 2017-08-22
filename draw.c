/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:36:17 by wfung             #+#    #+#             */
/*   Updated: 2017/08/21 19:09:03 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_right(void *mlx, void *win, t_env *e)
{
	int		i;
	int		j;
	float		tmp;
//	float	slope;
	i = 0;
	printf("DRAW RIGHT\n");
	while (i < e->row)
	{
		j = 0;
//		printf("D-right [%i][%i]\n", i, j);
		while (j < e->col)
		{
			tmp = e->pts[i][j].x;
//			printf("next%f\n", e->pts[i][j + 1].x);
			while (j + 1 < e->col && tmp <= e->pts[i][j + 1].x)
			{
//				printf("tmpx[%f][y%f]\n", tmp, e->pts[i][j].y);
				mlx_pixel_put(mlx, win, tmp, e->pts[i][j].y, 0xff0000);	//red
				tmp++;
			}
//			printf("\n");
			j++;
		}
		i++;
	}
}

void		draw_down(void *mlx, void *win, t_env *e)
{
	int		i;
	int		j;
	float		tmp;
//	float	slope;

	i = 0;
	printf("DRAW DOWN\n");
	while (i < e->row - 1)
	{
		j = 0;
//		printf("D-Down [%i][%i]\n", i, j);
		while (j < e->col)
		{
//			printf("current i%ij%i\n", i, j);
			tmp = e->pts[i][j].y;
//			printf("tmp%fnext%f\n", tmp, e->pts[i+1][j].y);
			while (tmp <= e->pts[i+1][j].y)
			{
//				printf("x[%f]tmpy[%f]next[%f]\n", e->pts[i][j].x, tmp, e->pts[i+1][j].y);
				mlx_pixel_put(mlx, win, e->pts[i][j].x, tmp, 0xff00);	//green
				tmp++;
			}
//			printf("\n");
			j++;
		}
		i++;
	}
}

//psuedo
//
//while i
//	i++;
//	while j
//		slope check
//			slope == 0 - draw straight
//			slope > -1 && < 1 == gradual?
//			else	sharp?
//	j++;
//
//		inside anyone of the 3 slope situations
//			change x depending on y or vice version
//			if no slope, draw straight
//
//rotate?
//translate
//
/*
void		draw_sharp()
{

}

void		draw_gradual()
{

}
*/
void		draw(void *mlx, void *win, t_env *e)
{
/*	int		i;
	int		j;
	float	m;

	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			j++;
		}
		i++;
	}
*/	
	draw_right(mlx, win, e);
	draw_down(mlx, win, e);
	printf("drawend\n");
}
