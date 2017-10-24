/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:22:52 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:47:58 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

char	*ft_strchr(const char *s, int c)
{
	char	mark;

	mark = (char)c;
	while ((*s != mark) && (*s != '\0'))
		s++;
	if (*s == mark)
		return ((char *)s);
	return (NULL);
}
