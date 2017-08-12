/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:13:44 by wfung             #+#    #+#             */
/*   Updated: 2017/08/11 15:31:20 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//need to remove strsplit sections if malloc fails??
static t_env	*strsplit_store(char **av, t_env *e)
{
	int		i;
	int		j;
	int		fd;
	char	**buff;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = 0;
	printf("hi\n");
	while (get_next_line(fd, &line) == 1)
	{
		if (!(buff = ft_strsplit(line, ' ')))
			return (NULL);
		j = 0;
		while (j < e->col)
		{
			e->array_int[i][j] = ft_atoi(buff[j]);
			free(buff[j]);
			buff[j] = NULL;
			j++;
		}
		free(buff);
		buff = NULL;
		free(line);
		i++;
	}
	close(fd);
	return (e);
}

int					save_values(char **av, t_env *e)
{
	int		i;

	i = 0;
	if (!(e->array_int = (int**)malloc(sizeof(int*) * (e->row))))
		return (0);
	while (i < e->col)
	{
		if (!(e->array_int[i] = (int*)malloc(sizeof(int) * (e->col))))
			//add free for this section
			return (0);
		i++;
	}
	if (!(strsplit_store(av, e)))
			return (0);
	return (1);
}
