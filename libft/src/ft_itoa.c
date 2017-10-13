/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:58:21 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 16:42:59 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void		ft_itoa_intermediate(intmax_t n, char *str, intmax_t size)
{
	intmax_t	i;
	intmax_t	rec;

	rec = n;
	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	if (rec < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_reverse(str, size);
}

static intmax_t	calcul_int(intmax_t n, intmax_t i)
{
	intmax_t	tmp;

	tmp = n;
	if (tmp <= 0)
	{
		tmp = -tmp;
		i++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	intmax_t	i;
	char		*str;
	char		*result;

	i = 0;
	if (n > 9223372036854775807)
		return (NULL);
	else if (n < -9223372036854775807)
		return ("-9223372036854775808");
	i = calcul_int(n, i);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		ft_error("Malloc Allocation --> ft_itoa");
	ft_itoa_intermediate(n, str, i);
	result = str;
	free(str);
	return (result);
}
