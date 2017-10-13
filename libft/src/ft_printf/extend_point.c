/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:47:06 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:07 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int			false_s(t_setting *sett, int asous, int i)
{
	int		tmp;

	if (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
	{
		tmp = sett->p_pct;
		while (sett->form[sett->p_pct] >= '0' &&
				sett->form[sett->p_pct] <= '9')
			sett->p_pct = sett->p_pct + 1;
		if (sett->flag->s_sharp)
			sharp(sett);
		if (ft_tolower(sett->conv) == 'c' || sett->conv == '%')
			return (0);
		if (sett->flag->s_sharp && sett->conv == 'o')
			asous++;
		while (i < (ft_atoi(&sett->form[tmp]) - asous))
		{
			ft_putchar('0');
			increment(1, 0);
			i++;
		}
		return (0);
	}
	if (sett->flag->s_sharp)
		sharp(sett);
	return (0);
}

int			true_min_s(t_setting *sett, int i)
{
	int		tmp;

	if (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
	{
		tmp = sett->p_pct;
		while (sett->form[sett->p_pct] >= '0' &&
				sett->form[sett->p_pct] <= '9')
			sett->p_pct = sett->p_pct + 1;
		while (i < ft_atoi(&sett->form[tmp]) &&
				i < ((int)ft_strlen(sett->stor->s_ap)))
		{
			ft_putchar(sett->stor->s_ap[i]);
			increment(1, 0);
			i++;
		}
	}
	return (0);
}

int			true_max_s(t_setting *sett, int i)
{
	int		tmp;
	int		e;

	e = 0;
	if (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
	{
		tmp = sett->p_pct;
		while (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
			sett->p_pct = sett->p_pct + 1;
		while (e < ft_atoi(&sett->form[tmp]) &&
				e < ((int)ft_strlen(ft_wstrtoa(sett->stor->w_ap))) &&
				(((int)ft_strlen(ft_wchartoa(sett->stor->w_ap[i]))) + e)
				<= ft_atoi(&sett->form[tmp]))
		{
			ft_putstr(ft_wchartoa(sett->stor->w_ap[i]));
			increment(ft_strlen(ft_wchartoa(sett->stor->w_ap[i])), 0);
			e = e + ft_strlen(ft_wchartoa(sett->stor->w_ap[i]));
			i++;
		}
	}
	return (0);
}
