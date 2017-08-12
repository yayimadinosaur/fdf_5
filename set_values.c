/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 20:49:48 by wfung             #+#    #+#             */
/*   Updated: 2017/08/11 20:55:17 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pts	**ft_setpts1( t_env *e)
{
	t_pts	**pts;
	int		i;
	int		j;

	i = 0;
	if (!(pts = (t_pts**)malloc(sizeof(t_pts*) * (e->row))))
		return (NULL);
	while (i < e->row)
	{
		j = 0;
			if (!(pts[i] = (t_pts*)malloc(sizeof(t_pts) * (e->col))))
				return (NULL);
		while (j < e->col)
		{
			pts[i][j].x = e->gap1 * j;
			pts[i][j].y = e->gap1 * i;
			pts[i][j].z = e->array_int[i][j];
		//	pts[i][j].x_stop = (e->gap1 * j);	//remember to flip x + y accordingly
		//	pts[i][j].y_stop = (e->gap1 * i);
		if (j + 1 < e->col)
			pts[i][j].x_stop = e->gap1 * (j + 1);	//remember to flip x + y accordingly
		if (i + 1 < e->row)
			pts[i][j].y_stop = e->gap1 * (i + 1);
			printf("i%ij%i]pts[x=%f][y=%f][z=%f][x_stop=%f][y_stop=%f]\n", i, j, pts[i][j].x, pts[i][j].y, pts[i][j].z, pts[i][j].x_stop, pts[i][j].y_stop);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("setpts1 done i%ij%i\n", i, j);
	return (pts);
}

static t_env	*set_window1(int n, t_env *e)
{
	printf("test now\n");
	if (n < 0)
		ft_putstr("window size needs to be positive\n");
	if (n == 0)
		ft_putstr("window size needs to be > 0\n");
	e->win_size_x = n;
	e->win_size_y = n;
	e->win_mid_x = n / 2;
	e->win_mid_y = n / 2;
	e->start_x = 0;
	e->start_y = 0;
	e->end_x = n - (2 * (n / 10));
	e->end_y = n - (2 * (n / 10));
	e->h_gap = (e->end_y - e->start_y) / (e->row - 1);
	e->w_gap = (e->end_x - e->start_x) / (e->col - 1);
	e->gap1 = (e->h_gap >= e->w_gap ? e->w_gap : e->h_gap);
	e->pts = ft_setpts1(e);
	e->max_x = e->gap1 * (e->col - 1);
	e->max_y = e->gap1 * (e->row - 1);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, e->win_size_x, e->win_size_y, "42");
	printf("uhoh\n");
	return (e);
}

void			set_values(int win_size, t_env *e)
{
	printf("test here\n");
	set_window1(win_size, e);
//	return (e);
}
