/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:54:01 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:42:57 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	while (s2[i] != '\0')
	{
		s1[len] = s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
