/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:44:30 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:23 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void			sharp(t_setting *sett)
{
	if (ft_tolower(sett->conv) == 'x' && sett->stor->i_ap)
	{
		ft_putchar('0');
		ft_putchar(sett->conv);
		increment(2, 0);
	}
	else if (sett->conv == 'p')
	{
		ft_putstr("0x");
		increment(2, 0);
	}
	else if (sett->conv == 'o' && sett->stor->i_ap)
	{
		ft_putchar('0');
		increment(1, 0);
	}
}

static void		space(t_setting *sett)
{
	while (sett->form[sett->p_pct] == ' ')
		sett->p_pct = sett->p_pct + 1;
	if (sett->conv == 'd' && sett->stor->d_ap >= 0)
	{
		ft_putchar(' ');
		increment(1, 0);
	}
}

int				res_sort(t_setting *sett)
{
	int			minus;

	if (sett->flag->s_space)
		space(sett);
	if (!sett->flag->s_zero)
		minus = number(sett);
	if (sett->flag->s_sharp && !sett->flag->s_point)
		sharp(sett);
	if (sett->flag->s_zero)
		minus = number(sett);
	return (minus);
}

static void		spe_flag_match(t_setting *sett)
{
	if (sett->form[sett->p_pct] == 'h')
	{
		if (sett->form[sett->p_pct + 1] == 'h')
			sett->sflag = hh;
		else
			sett->sflag = h;
	}
	else if (sett->form[sett->p_pct] == 'l')
	{
		if (sett->form[sett->p_pct + 1] == 'l')
			sett->sflag = ll;
		else
			sett->sflag = l;
	}
	else if (sett->form[sett->p_pct] == 'j')
		sett->sflag = j;
	else if (sett->form[sett->p_pct] == 'z')
		sett->sflag = z;
	if (sett->sflag == hh || sett->sflag == ll)
		sett->p_pct = sett->p_pct + 2;
	else if (sett->sflag == NONE)
		sett->p_pct = sett->p_pct;
	else
		sett->p_pct = sett->p_pct + 1;
}

void			flag_match(t_setting *sett)
{
	while (ft_strchr("0# +-", sett->form[sett->p_pct]))
	{
		if (sett->form[sett->p_pct] == '0' && !sett->flag->s_minus)
			sett->flag->s_zero = 1;
		if (sett->form[sett->p_pct] == '#')
			sett->flag->s_sharp = 1;
		if (sett->form[sett->p_pct] == ' ' && !sett->flag->s_plus)
			sett->flag->s_space = 1;
		if (sett->form[sett->p_pct] == '+')
		{
			sett->flag->s_space = 0;
			sett->flag->s_plus = 1;
		}
		if (sett->form[sett->p_pct] == '-')
		{
			sett->flag->s_zero = 0;
			sett->flag->s_minus = 1;
		}
		sett->p_pct = sett->p_pct + 1;
	}
	spe_flag_match(sett);
}
