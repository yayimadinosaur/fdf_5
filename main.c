/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/08/11 20:52:27 by wfung            ###   ########.fr       */
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
	set_values(600, e);
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
			"max_x %f\n"
			"max_y %f\n"
			"row %i\n"
			"col %i\n"
			, e->win_size_x, e->win_size_y, e->win_mid_x, e->win_mid_y, e->start_x,
			e->start_y, e->end_x, e->end_y, e->gap1, e->max_x, e->max_y, e->row,
			e->col);
	return (0);
}