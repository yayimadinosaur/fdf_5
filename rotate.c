/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:48:03 by wfung             #+#    #+#             */
/*   Updated: 2017/08/23 17:55:35 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			e->pts[i][j].x2 = (e->pts[i][j].x * cos(0.7845)) - (e->pts[i][j].y * sin(0.7845));
			e->pts[i][j].y2 = (e->pts[i][j].y * sin(0.7845)) - (e->pts[i][j].x * cos(0.7845));
			j++;
		}
		i++;
	}
}

//see if values are correct of rotated
