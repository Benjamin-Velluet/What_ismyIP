/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:39:30 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:32:59 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char		*conv_x(t_setting *sett)
{
	char	*result;

	result = ft_itoa_base(sett->stor->i_ap, 16);
	return (result);
}

char		*conv_o(t_setting *sett)
{
	char	*result;

	result = ft_itoa_base(sett->stor->i_ap, 8);
	return (result);
}

char		*conv_u(t_setting *sett)
{
	char	*result;

	result = ft_itoa_base(sett->stor->i_ap, 10);
	return (result);
}

char		*conv_d(t_setting *sett)
{
	char	*result;

	result = ft_itoa(sett->stor->d_ap);
	return (result);
}

char		*conv_b(t_setting *sett)
{
	char	*result;

	result = ft_itoa_base(sett->stor->i_ap, 2);
	return (result);
}
