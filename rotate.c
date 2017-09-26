/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:48:03 by wfung             #+#    #+#             */
/*   Updated: 2017/09/25 17:24:34 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			e->pts[i][j].y = (e->pts[i][j].y * cos(0.7845)) - (e->pts[i][j].z * sin(0.7845));
			e->pts[i][j].z = (e->pts[i][j].y * sin(0.7845)) + (e->pts[i][j].z * cos(0.7845));
			j++;
		}
		i++;
	}
}

static void	rotate_y(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			e->pts[i][j].x = (e->pts[i][j].x * cos(0.7845)) + (e->pts[i][j].z * sin(0.7845));
			e->pts[i][j].z = -(e->pts[i][j].x * sin(0.7845)) + (e->pts[i][j].z * cos(0.7845));
			j++;
		}
		i++;
	}
}

static void	rotate_z(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->col)
	{
		j = 0;
		while (j < e->row)
		{
			e->pts[i][j].x = (e->pts[i][j].x * cos(0.7845)) - (e->pts[i][j].y * sin(0.7845));
			e->pts[i][j].y = (e->pts[i][j].x * sin(0.7845)) + (e->pts[i][j].y * cos(0.7845));
			j++;
		}
		i++;
	}
}

void	rotate(t_env *e)
{
	rotate_x(e);
	rotate_y(e);
	rotate_z(e);
}
//see if values are correct of rotated
