/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:44:25 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:09:44 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void		*ft_memcpy_rev(void *dst, const void *src, size_t len)
{
	char		*temp1;
	char		*temp2;

	if (!len || dst == src)
		return (dst);
	temp1 = (char *)dst;
	temp2 = (char *)src;
	while (len--)
		temp1[len] = temp2[len];
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
		return (ft_memcpy_rev(dst, src, len));
	return (dst);
}
