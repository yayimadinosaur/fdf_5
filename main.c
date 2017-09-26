/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/09/25 17:28:11 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//uses create_struct2.c
//uses set_window2.c
int		main(int ac, char **av)
{
	t_env	*e;
	if (ac != 2)
		ft_puterror("Please include a .fdf file");
	e = parse_fdf(av);
	ft_putstr(".fdf parsing filename + file contents  pass!\n");	//
	set_values2(600, e, av);
	//printf("struct values\nw_size_x %i\nw_size_y %i\nw_mid_x %f\nw_mid_y %f\nstart_x %i\nstart_y %i\nend_x %f\nend_y %f\ngap %f\nrow %i\ncol %i\n",
//	e->win_size_x, e->win_size_y, e->win_mid_x, e->win_mid_y, e->start_x,
//	e->start_y, e->end_x, e->end_y, e->gap, e->row, e->col);
	// testing array_int - pts
//	print_test(e);
	//fin test
	rotate(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 600, 600, "42");
	//rotate
	//translate
	draw1(e);
	mlx_loop(e->mlx);
	return (0);
}
