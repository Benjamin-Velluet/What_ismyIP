/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bepositive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:56:38 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:06:44 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_bepositive(intmax_t nbr)
{
	if (!nbr || nbr >= 0)
		return (-1);
	else
		nbr = 0 - nbr;
	return (nbr);
}
