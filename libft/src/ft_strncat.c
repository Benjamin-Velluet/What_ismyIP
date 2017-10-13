/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:08:08 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:13:11 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	int		i;
	int		max;

	max = (int)n;
	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	while ((s2[i] != '\0') && (i < max))
	{
		s1[len] = s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
