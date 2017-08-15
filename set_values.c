/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 20:49:48 by wfung             #+#    #+#             */
/*   Updated: 2017/08/14 19:23:54 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		clean_strsplit(char **buff, char *line, t_env *e, int range)
{
	int		i;

	i = range;
	free(line);
	if (!buff)
	{
		free(e);
		ft_puterror("strsplit failed\n");
	}
	while (i > -1)
	{
		free(buff[i]);
		i--;
	}
	free(buff);
}

static void		setpts2(t_env *e, int i, int j)
{
	printf("setpts2 chk i%ij%i\n", i, j);
	printf("e->pts[%i][%i].x = %f\n", i, j, e->pts[i][j].x);
	e->pts[i][j].x = e->gap * j;
	printf("setpts2 xgap\n");
	e->pts[i][j].y = e->gap * i;
	printf("setpts2 ygap\n");
//	e->pts[i][j].z = e->array_int[i][j];
	(j + 1 < e->col) ? (e->pts[i][j].x_stop = e->gap * (j + 1)) : (e->pts[i][j].x_stop = 0);	//cmp x w/ x_stop, if x > x_stop, dont draw
	printf("setpts2 xxxxxgap\n");
	(i + 1 < e->row) ? (e->pts[i][j].y_stop = e->gap * (i + 1)) : (e->pts[i][j].y_stop = 0);	//cmp y w/ y_stop, if y > y_stop, dont draw
	printf("setpts2 chkfin\n");
}

static t_pts	**setpts1(t_env *e)
{
	t_pts	**pts;
	int		i;
	int		j;

	i = 0;
	printf("setpts1chk row %i col %i\n", e->row, e->col);
	if (!(pts = (t_pts**)malloc(sizeof(t_pts*) * (e->row))))
		return (NULL);
	while (i < e->row)
	{
		j = 0;
		if (!(pts[i] = (t_pts*)malloc(sizeof(t_pts) * (e->col))))
			return (NULL);
		while (j < e->col)
		{
			printf("chk i %i j %i\n", i, j);
			setpts2(e, i, j);
			printf("chk2 i %i j %i\n", i,  j);
			e->pts[i][j].z = e->array_int[i][j];
			printf("chk3 i %i j %i\n", i, j);
			j++;
		}
		i++;
	}
	return (pts);
}

static void	set_window1(int n, t_env *e)
{
	printf("set values - set window1 1\n");
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
	e->gap = (e->h_gap >= e->w_gap ? e->w_gap : e->h_gap);
	e->pts = setpts1(e);
	e->max_x = e->gap * (e->col - 1);
	e->max_y = e->gap * (e->row - 1);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, e->win_size_x, e->win_size_y, "42");
	printf("set values - set window done\n");
	//return (e);	//dont need for void?
}

void			set_values(int win_size, t_env *e, char **av)
{
	int		i;
	int		j;
	char	*line;
	char	**buff;
	int		fd;

	i = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file reading failed\n");
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		if (!(buff = ft_strsplit(line, ' ')))
			clean_strsplit(buff, line, e, e->col);
		while (j < e->col)
		{
			e->array_int[i][j] = ft_atoi(buff[j]);
			printf("e->array_int[%i]%i] = %i\n", i, j,e->array_int[i][j]);
			j++;
		}
		clean_strsplit(buff, line, e, e->col);
		i++;
	}
	printf("setvalues i%ij%i\n", i, j);
	close(fd);
	set_window1(win_size, e);
}
