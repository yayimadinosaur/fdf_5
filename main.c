/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/08/19 16:27:29 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//uses create_struct2.c
//uses set_window2.c
int		main(int ac, char **av)
{
	t_env	*e;
	int		i = 0;//
	int		j;//
	if (ac != 2)
		ft_puterror("Please include a .fdf file");
	e = parse_fdf(av);
	ft_putstr(".fdf parsing filename + file contents  pass!\n");	//
	set_values2(600, e, av);
	printf("struct values\nw_size_x %i\nw_size_y %i\nw_mid_x %f\nw_mid_y %f\nstart_x %i\nstart_y %i\nend_x %f\nend_y %f\ngap %f\nrow %i\ncol %i\n",
	e->win_size_x, e->win_size_y, e->win_mid_x, e->win_mid_y, e->start_x,
	e->start_y, e->end_x, e->end_y, e->gap, e->row, e->col);
	// testing array_int - pts
	printf("-----------------------------------\n");
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			printf("[i%i][j%i]\n[x(%f)][y(%f)][z(%f)]\n", i, j, e->pts[i][j].x, e->pts[i][j].y, e->pts[i][j].z);
			printf("[x2(%f)][y2(%f)]\n", e->pts[i][j].x2, e->pts[i][j].y2);
		//	printf("[x_s%f][y_s%f]\n", e->pts[i][j].x_stop, e->pts[i][j].y_stop);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("fin array_int\n");
	printf("-----------------------------------\n");
	//fin test
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 600, 600, "42");
	draw(e->mlx, e->win, e);
	mlx_loop(e->mlx);
	return (0);
}
