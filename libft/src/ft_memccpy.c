/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:59:28 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:09:23 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dst_tmp;
	char		*src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = 0;
	while (i < n)
	{
		if ((*dst_tmp++ = *src_tmp++) == c)
		{
			return (dst_tmp);
		}
		i++;
	}
	return (NULL);
}
