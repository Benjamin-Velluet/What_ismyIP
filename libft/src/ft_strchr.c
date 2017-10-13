/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:22:52 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:11:30 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
