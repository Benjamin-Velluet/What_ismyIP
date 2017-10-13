/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 23:10:21 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:32:48 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	point_actif(t_setting *sett, int asous)
{
	int		i;

	i = 0;
	sett->p_pct = sett->p_pct + 1;
	if (ft_tolower(sett->conv) != 's')
		return (false_s(sett, asous, i));
	else if (sett->conv == 's')
		return (true_min_s(sett, i));
	else
		return (true_max_s(sett, i));
}

static int	extra_point_down(t_setting *sett, int i, int tmp, int asous)
{
	int		e;

	e = 0;
	if (sett->conv == 's')
	{
		while (i < ft_atoi(&sett->form[tmp]) &&
				i < ((int)ft_strlen(sett->stor->s_ap)))
			i++;
		return (i);
	}
	else if (sett->conv == 'S')
	{
		while (e < ft_atoi(&sett->form[tmp]) &&
				e < ((int)ft_strlen(ft_wstrtoa(sett->stor->w_ap))) &&
				(((int)ft_strlen(ft_wchartoa(sett->stor->w_ap[i]))) + e)
				<= ft_atoi(&sett->form[tmp]))
		{
			e = e + ft_strlen(ft_wchartoa(sett->stor->w_ap[i]));
			i++;
		}
		return (e);
	}
	return (asous + i);
}

static int	point_down(t_setting *sett, int asous)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = sett->p_pct + 1;
	if (ft_tolower(sett->conv) != 's')
	{
		if (sett->form[tmp] >= '0' && sett->form[tmp] <= '9')
		{
			while (i < (ft_atoi(&sett->form[tmp]) - asous))
				i++;
		}
		if (sett->conv == 'd' && sett->stor->d_ap < 0)
			asous++;
		if (sett->conv == 'c' && sett->stor->c_ap != 0)
			return (asous);
		else if (i > asous)
			return (i);
	}
	return (extra_point_down(sett, i, tmp, asous));
}

int			verif_point(t_setting *sett, int on)
{
	int		asous;
	int		i;

	i = 0;
	asous = calcul_asous(sett);
	if (sett->form[sett->p_pct] == '.')
	{
		sett->flag->s_point = 1;
		true_print(sett);
		if ((sett->conv == 'x' || sett->conv == 'o') && !sett->stor->i_ap)
			asous = 0;
		else if (sett->conv == 'd' && sett->stor->d_ap <= 0)
			asous--;
		if (on == 0)
			return (point_down(sett, asous));
		else
			return (point_actif(sett, asous));
	}
	return (asous + i);
}
