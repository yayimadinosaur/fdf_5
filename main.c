/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:50:09 by wfung             #+#    #+#             */
/*   Updated: 2017/08/11 16:46:14 by wfung            ###   ########.fr       */
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
	return (0);
}
