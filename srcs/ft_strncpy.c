/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:13:22 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:48:36 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;

	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i = i + 1;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i = i + 1;
	}
	return (dst);
}
