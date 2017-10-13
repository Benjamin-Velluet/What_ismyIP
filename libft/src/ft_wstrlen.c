/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:07:52 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:14:38 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int		i;

	i = 0;
	if (!wstr)
		return (0);
	while (wstr[i])
		i++;
	return (i);
}
