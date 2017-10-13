/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:17:34 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:36 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int		change_asous(t_setting *sett, int asous)
{
	if (sett->flag->s_space)
		asous++;
	if ((ft_tolower(sett->conv) == 'x' && sett->flag->s_sharp) ||
			sett->conv == 'p')
		asous = asous + 2;
	else if (sett->conv == 'o' && sett->flag->s_sharp && sett->stor->i_ap)
		asous++;
	else if (sett->conv == 'd' && sett->stor->d_ap >= 0 && sett->flag->s_plus)
		asous++;
	return (asous);
}

static void		spe_number(t_setting *sett, int i)
{
	int		e;

	e = 0;
	if (sett->conv == 'd' && sett->stor->d_ap < 0)
	{
		ft_putchar('-');
		increment(1, 0);
	}
	else if (sett->conv == 'd' && sett->stor->d_ap >= 0 &&
			sett->flag->s_plus)
	{
		ft_putchar('+');
		increment(1, 0);
	}
	if (sett->flag->s_zero == 1)
	{
		while (e < i)
		{
			ft_putchar('0');
			e++;
		}
	}
}

static int		sign_number(t_setting *sett, int asous, int p_numb, int i)
{
	while (i < (ft_atoi(&sett->form[p_numb]) - asous))
		i++;
	if (sett->conv == 'd' && sett->stor->d_ap < 0)
	{
		ft_putchar('-');
		increment(1, 0);
	}
	else if (sett->conv == 'd' && sett->stor->d_ap >= 0 &&
			sett->flag->s_plus)
	{
		ft_putchar('+');
		increment(1, 0);
	}
	verif_point(sett, 1);
	return (i);
}

static int		finish_number(t_setting *sett, int p_numb)
{
	int			i;
	int			asous;

	i = 0;
	asous = verif_point(sett, 0);
	asous = change_asous(sett, asous);
	if (sett->flag->s_minus != 1 && p_numb > 0)
	{
		if (sett->conv == 'd' && sett->flag->s_point && sett->flag->s_zero)
			sett->flag->s_zero = 0;
		while (i < (ft_atoi(&sett->form[p_numb]) - asous))
		{
			if (sett->flag->s_zero != 1)
				ft_putchar(' ');
			increment(1, 0);
			i++;
		}
		spe_number(sett, i);
	}
	else
		return (sign_number(sett, asous, p_numb, i));
	verif_point(sett, 1);
	return (0);
}

int				number(t_setting *sett)
{
	int			p_numb;
	int			result;

	p_numb = 0;
	if (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
		p_numb = sett->p_pct;
	while (sett->form[sett->p_pct] >= '0' && sett->form[sett->p_pct] <= '9')
		sett->p_pct = sett->p_pct + 1;
	result = finish_number(sett, p_numb);
	return (result);
}
