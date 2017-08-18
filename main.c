/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/08/17 19:32:13 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//uses create_struct2.c
//uses set_window2.c
int		main(int ac, char **av)
{
	t_env	*e;
	int		i = 0;//
	int		j = 0;//
	if (ac != 2)
		ft_puterror("Please include a .fdf file");
	e = parse_fdf(av);
	ft_putstr(".fdf parsing filename + file contents  pass!\n");	//
	set_values1(600, e, av);
	printf("test spot\n");
	printf("struct values\n"
			"w_size_x %i\n"
			"w_size_y %i\n"
			"w_mid_x %f\n"
			"w_mid_y %f\n"
			"start_x %i\n"
			"start_y %i\n"
			"end_x %f\n"
			"end_y %f\n"
			"gap %f\n"
		//	"max_x %f\n"
		//	"max_y %f\n"
			"row %i\n"
			"col %i\n"
			, e->win_size_x, e->win_size_y, e->win_mid_x, e->win_mid_y, e->start_x,
			e->start_y, e->end_x, e->end_y, e->gap, e->row, e->col);
	// testing array_int - pts
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			printf("[i%i][j%i][x%f][y%f][z%f]", i, j, e->pts[i][j].x, e->pts[i][j].y, e->pts[i][j].z);
			printf("[x_s%f][y_s%f]", e->pts[i][j].x_stop, e->pts[i][j].y_stop);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("fin array_int\n");
	//fin test
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 600, 600, "42");
	draw(e->mlx, e->win, e);
	mlx_loop(e->mlx);
	return (0);
}
