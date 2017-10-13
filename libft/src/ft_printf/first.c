/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:45:31 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:17 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int				increment(int nbr, int reset)
{
	static int	result = 0;
	static int	error = 0;

	if (reset == 1)
		result = 0;
	else if (reset == -1)
		error = -1;
	if (error == -1)
		result = -1;
	else
		result = result + nbr;
	return (result);
}

static int		extra_signelen(t_setting *sett)
{
	if (sett->form[sett->p_pct] == '~')
	{
		if (sett->form[sett->p_pct + 1] != '~')
		{
			sett->p_pct = sett->p_pct + 1;
			return (2);
		}
		else
		{
			ft_putchar(sett->form[sett->p_pct]);
			increment(1, 0);
			sett->p_pct = sett->p_pct + 2;
		}
	}
	else
	{
		ft_putchar(sett->form[sett->p_pct]);
		increment(1, 0);
		sett->p_pct = sett->p_pct + 1;
	}
	return (0);
}

static int		signelen(t_setting *sett)
{
	if (sett->form[sett->p_pct] == '\0')
		return (0);
	while (sett->form[sett->p_pct])
	{
		if (sett->form[sett->p_pct] == '%')
		{
			if (sett->form[sett->p_pct + 1] != '%')
			{
				sett->p_pct = sett->p_pct + 1;
				return (1);
			}
			else
			{
				ft_putchar(sett->form[sett->p_pct]);
				increment(1, 0);
				sett->p_pct = sett->p_pct + 2;
			}
		}
		else
		{
			if (extra_signelen(sett) == 2)
				return (2);
		}
	}
	return (0);
}

int				verif_signe(t_setting *sett)
{
	int			match;

	match = signelen(sett);
	if (match == 0)
		return (match);
	else if (match == 1)
		return (1);
	else
		color(sett);
	return (verif_signe(sett));
}

void			flag_init(t_setting *sett)
{
	sett->print = 1;
	sett->stor->i_ap = 0;
	sett->stor->s_ap = NULL;
	sett->flag->s_zero = 0;
	sett->flag->s_sharp = 0;
	sett->flag->s_space = 0;
	sett->flag->s_plus = 0;
	sett->flag->s_minus = 0;
	sett->flag->s_point = 0;
	sett->sflag = NONE;
}
