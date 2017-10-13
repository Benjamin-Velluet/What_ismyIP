/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:18:11 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:09:32 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	if ((s1 == NULL) && (s2 == NULL) && (n == 0))
		return (0);
	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
		n--;
	}
	return (0);
}
