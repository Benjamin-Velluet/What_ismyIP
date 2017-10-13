/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearchlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:42:43 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:13:52 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t		ft_strsearchlen(const char *s, int i, const char r)
{
	int		e;

	e = 0;
	if (i >= (int)ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (s[i] == r)
			return (e + 1);
		i++;
		e++;
	}
	if (r == '\0')
		return (e - 1);
	return (0);
}
