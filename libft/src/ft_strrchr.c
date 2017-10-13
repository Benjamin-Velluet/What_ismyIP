/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:45:43 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:13:47 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mark;

	mark = (char *)s + ft_strlen(s);
	while (*mark != (char)c)
	{
		if (mark == s)
		{
			return (NULL);
		}
		mark--;
	}
	return (mark);
}
