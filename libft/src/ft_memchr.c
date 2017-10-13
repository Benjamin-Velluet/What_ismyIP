/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:24:44 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:09:27 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chk;
	unsigned char	mark;
	int				i;

	i = 0;
	mark = (unsigned char)c;
	chk = (unsigned char *)s;
	while (n > 0)
	{
		if (chk[i] == mark)
			return (chk + i);
		i++;
		n--;
	}
	return (NULL);
}
