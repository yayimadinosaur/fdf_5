/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:36:17 by wfung             #+#    #+#             */
/*   Updated: 2017/08/17 20:01:23 by wfung            ###   ########.fr       */
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
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			tmp = e->pts[i][j].x;
			while (tmp <= e->pts[i][j + 1].x_stop && tmp <= e->end_x)
			{
			mlx_pixel_put(mlx, win, tmp, e->pts[i][j].y, 0xff0000);	//red
		//	printf("[x]%f[y]%f]\n", tmp, e->pts[i][j].y);
			tmp++;
			}
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
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			tmp = e->pts[i][j].y;
			printf("tmpset = %f\n", tmp);
		//	printf("tmp = %f\n", tmp);
			while (tmp <= e->pts[i][j + 1].y_stop)
			{
			mlx_pixel_put(mlx, win, e->pts[i][j].x, tmp, 0xff00);	//green
		//	printf("[x]%f[y]%f]\n", e->pts[i][j].x, tmp);
			tmp++;
			}
			printf("[%i][%i][x]%f[y]%f]\n", i, j,  e->pts[i][j].x, tmp);
	//		printf("draw iter i%ij%i\n", i, j);
			j++;
		}
		i++;
	}
	printf("draw end [x%f][y%f]\n", e->pts[i-1][j - 1].x, tmp);
}

/*
void		draw_straight()
{

}

void		draw_sharp()
{

}

void		draw_gradual()
{

}
*/
void		draw(void *mlx, void *win, t_env *e)
{
	draw_right(mlx, win, e);
	draw_down(mlx, win, e);
}
