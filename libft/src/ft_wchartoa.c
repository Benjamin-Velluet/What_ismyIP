/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:37:08 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:07:59 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		cut(wint_t wint)
{
	if (wint <= 0x7F)
		return (1);
	else if (wint <= 0x7FF)
		return (2);
	else if (wint <= 0xFFFF)
		return (3);
	else if (wint <= 0x10FFFF)
		return (4);
	return (0);
}

static char		*fuck_the_norm(char *str, wint_t wint)
{
	char		*res;
	char		*result;

	if (!(res = malloc(sizeof(char) * (cut(wint) + 1))))
		ft_error("Malloc Allocation ---> ft_wchartoa");
	ft_strncpy(res, str, cut(wint));
	res[cut(wint)] = '\0';
	result = res;
	free(res);
	return (res);
}

char			*ft_wchartoa(wint_t wint)
{
	char		str[4];
	char		*result;

	if (cut(wint) == 1)
		str[0] = wint;
	else if (cut(wint) == 2)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
	}
	else if (cut(wint) == 3)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
	}
	else if (cut(wint) == 4)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
	}
	result = fuck_the_norm(str, wint);
	return (result);
}
