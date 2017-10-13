/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 22:42:54 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:09:02 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		countwstr(wchar_t *wstr)
{
	int		i;
	int		e;

	e = 0;
	i = 0;
	if (!wstr)
		return (0);
	while (wstr[i])
	{
		if (wstr[i] <= 0x7F)
			e++;
		else if (wstr[i] <= 0x7FF)
			e = e + 2;
		else if (wstr[i] <= 0xFFFF)
			e = e + 3;
		else if (wstr[i] <= 0x10FFFF)
			e = e + 4;
		i++;
	}
	return (e);
}

char			*ft_wstrtoa(wchar_t *wstr)
{
	int		i;
	char	*result;
	char	*tmp;

	result = NULL;
	i = 0;
	tmp = "\0";
	if (wstr[i] == 175318282)
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * (countwstr(wstr) + 1))))
		ft_error("Malloc Allocation ---> ft_wstrtoa");
	ft_bzero(tmp, countwstr(wstr) + 1);
	while (wstr[i])
	{
		ft_strcat(tmp, ft_wchartoa(wstr[i]));
		i++;
	}
	result = tmp;
	if (tmp != NULL)
		free(tmp);
	return (result);
}
