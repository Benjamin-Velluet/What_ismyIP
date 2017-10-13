/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:25:47 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:43 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	norme_asous(t_setting *sett, int asous)
{
	if (sett->conv == 'u' && sett->stor->i_ap)
		asous = ft_strlen(conv_u(sett));
	else if (sett->conv == 'b' && sett->stor->i_ap)
		asous = ft_strlen(conv_b(sett));
	else if (sett->conv == 'd')
		asous = ft_strlen(conv_d(sett));
	else if (ft_tolower(sett->conv) == 'c' || sett->conv == '%' ||
			sett->conv == '!')
		asous = 1;
	else if (sett->conv == 's')
	{
		if (sett->stor->s_ap == NULL)
			sett->stor->s_ap = "(null)";
		asous = ft_strlen(sett->stor->s_ap);
	}
	else if (sett->conv == 'S')
		asous = ft_strlen(ft_wstrtoa(sett->stor->w_ap));
	return (asous);
}

int			calcul_asous(t_setting *sett)
{
	int		asous;

	asous = 0;
	if (ft_tolower(sett->conv) == 'x' || sett->conv == 'p' || sett->conv == 'o')
	{
		if (sett->stor->i_ap)
		{
			if (sett->conv == 'o')
				asous = ft_strlen(conv_o(sett));
			else
				asous = ft_strlen(conv_x(sett));
		}
		else
			asous = 1;
	}
	else
		asous = norme_asous(sett, asous);
	return (asous);
}

void		true_print(t_setting *sett)
{
	int		result;

	result = 0;
	if (sett->conv == 'd' && sett->stor->d_ap)
		result = 1;
	else if (sett->conv == 'p' &&
			(sett->form[sett->p_pct + 1] >= '1' &&
			sett->form[sett->p_pct + 1] <= '9'))
		result = 1;
	else if (((ft_tolower(sett->conv) == 'x' || sett->conv == 'u' ||
					sett->conv == 'b' || sett->conv == 'o') &&
				sett->stor->i_ap) || (sett->conv == 'o' && sett->flag->s_sharp))
		result = 1;
	else if (ft_tolower(sett->conv) == 'c')
		result = 1;
	else if (sett->conv == '%')
		result = 1;
	if (result == 0 || sett->conv == 's')
		sett->print = 0;
}
