/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:50:00 by wfung             #+#    #+#             */
/*   Updated: 2016/12/16 19:33:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c < 0 || c > 255)
		return (c);
	else if ((unsigned char)c >= 65 && (unsigned char)c <= 90)
		c = c + 32;
	return ((int)c);
}
