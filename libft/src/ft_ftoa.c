/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:49:33 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 17:58:03 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char		*zero(intmax_t deci, intmax_t e, long double nbr)
{
	char		*zero;
	char		*freetmp;

	zero = malloc(sizeof(char) * 9 + e);
	ft_bzero(zero, 9 + e);
	if (e)
	{
		zero[0] = '-';
		zero[1] = '0';
		zero[2] = '.';
	}
	else
	{
		zero[0] = '0';
		zero[1] = '.';
	}
	while (ft_itoa(nbr)[6] >= '5' && ft_itoa(nbr)[6] <= '9')
		nbr++;
	deci = deci / 10;
	nbr = nbr / 10;
	deci = nbr - deci;
	ft_strcat(zero, ft_itoa(deci));
	freetmp = zero;
	free(zero);
	return (freetmp);
}

static char		*minus_ftoa(char *freetmp, intmax_t tmp)
{
	char		*minus;

	if (!(minus = malloc(sizeof(char) * tmp + 8)))
		ft_error("Malloc Allocation ---> ft_ftoa");
	ft_bzero(minus, tmp + 8);
	minus[0] = '-';
	ft_strcat(minus, freetmp);
	free(freetmp);
	freetmp = minus;
	free(minus);
	return (freetmp);
}

static char		*result_and_free(long double nbr, intmax_t deci, intmax_t tmp,
		intmax_t e)
{
	char		*freetmp;
	char		*str;

	if (tmp != -1)
	{
		if (!(str = malloc(sizeof(char) * tmp + 8)))
			ft_error("Malloc Allocation --> ft_ftoa");
	}
	else
		return (zero(deci, e, nbr));
	while (ft_itoa(nbr)[6 + tmp] >= '5' && ft_itoa(nbr)[6 + tmp] <= '9')
		nbr++;
	deci = deci / 10;
	nbr = nbr / 10;
	deci = nbr - deci;
	ft_bzero(str, tmp + 8);
	ft_strncpy(str, ft_itoa(nbr), tmp);
	str[tmp] = '.';
	ft_strcat(str, ft_itoa(deci));
	freetmp = str;
	if (e == 1)
		freetmp = minus_ftoa(freetmp, tmp);
	else
		free(str);
	return (freetmp);
}

static char		*ft_ftoa_intermediate(long double nbr, intmax_t deci,
		intmax_t tmp, intmax_t e)
{
	intmax_t	i;

	i = 0;
	while (nbr > ft_atoi(ft_itoa(nbr)) && nbr < (ft_atoi(ft_itoa(nbr)) + 1) &&
			i < 7 && ft_atoi(ft_itoa(nbr)) != 0)
	{
		i++;
		deci = deci * 10;
		nbr = nbr * 10;
	}
	while (i != 7)
	{
		deci = deci * 10;
		nbr = nbr * 10;
		i++;
	}
	return (result_and_free(nbr, deci, tmp, e));
}

char			*ft_ftoa(long double nbr)
{
	intmax_t	tmp;
	intmax_t	deci;
	intmax_t	e;

	tmp = 0;
	e = 0;
	if (!nbr)
		return ("0.000000");
	else if (nbr == ft_atoi(ft_itoa(nbr)))
		return (ft_strcat(ft_itoa(nbr), ".000000"));
	else if (nbr >= 2147488)
		return ("2147488.000000");
	else if (nbr <= -2147489)
		return ("-2147489.000000");
	else if (nbr < 0)
	{
		nbr = -nbr;
		e++;
	}
	deci = ft_atoi(ft_itoa(nbr));
	if (ft_atoi(ft_itoa(nbr)) == 0)
		tmp = -1;
	else
		tmp = tmp + ft_strlen(ft_itoa(nbr));
	return (ft_ftoa_intermediate(nbr, deci, tmp, e));
}
