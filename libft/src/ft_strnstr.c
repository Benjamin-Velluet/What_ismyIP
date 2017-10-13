/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:41:39 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:13:42 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	max;

	if (*little == '\0')
		return ((char *)big);
	max = ft_strlen(little);
	while ((*big != '\0') && (max <= len))
	{
		if ((*big == *little) && (ft_memcmp(big, little, max) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
