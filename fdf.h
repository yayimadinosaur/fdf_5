/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/08/24 15:40:59 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WHT 0xfffafa
#define	RED 0xff0000
#define GRN 0xff00


#include <stdio.h>	//

//values for the 3 pts; not sure if needed?
typedef struct			s_pts
{
	float					x;
	float					y;
	float					z;
	float					x2;	//x pixel stop
	float					y2;	//y pixel stop
	float					run;	//x2 - x1
	float					rise;	//y2 - y1
	float					m;	//slope of line = m
	float					offset;
	float					adjust;
}						t_pts;	//malloc for (**t_pts) row * col

typedef struct			s_env
{
	void				*mlx;
	void				*win;

	int					win_size_x;	//win
	int					win_size_y;	//win
	float				win_mid_x;	//win
	float				win_mid_y;	//win

	int					start_x;	//grid
	int					start_y;	//grid
	float				end_x;		//grid limit
	float				end_y;		//grid limit

	float				h_gap;			//remove
	float				w_gap;			//remove
	float				gap;

//	float				max_x;		
//	float				max_y;

	t_pts				**pts;

	int					row;
	int					col;
//	int					**array_int;
}						t_env;

t_env		*parse_fdf(char **av);

//void		set_values(int win_size, t_env *e, char **av);	//old
void		set_values2(int win_size, t_env *e, char **av);

t_pts		**create_struct(int row, int col);
void		array_int(char **result_str, int n, int *array);

//void		draw(void *mlx, void *win, t_env *e);
void		draw1(t_env *e);

//void		rotate(t_fdfstore *store, t_env *e);
//void		translate(t_fdfstore *store, t_env *e);
//
//ttest functions
//void		print_array_int(int **array_int, t_env *e);
//void		print_array_int(t_env *e);
void		print_test(t_env *e);
#endif
