/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 23:32:57 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:32:55 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	norme_color(t_setting *sett)
{
	ft_putstr("\033[");
	ft_putchar(sett->form[sett->p_pct]);
	ft_putchar(sett->form[sett->p_pct + 1]);
	ft_putchar('m');
	sett->p_pct = sett->p_pct + 2;
	sett->color = 1;
}

void	color(t_setting *sett)
{
	if (sett->form[sett->p_pct] >= '1' && sett->form[sett->p_pct] <= '9')
	{
		if (sett->form[sett->p_pct + 1] >= '0' &&
				sett->form[sett->p_pct + 1] <= '9')
			norme_color(sett);
		else
		{
			ft_putstr("\033[");
			ft_putchar(sett->form[sett->p_pct]);
			ft_putchar('m');
			sett->p_pct = sett->p_pct + 1;
		}
	}
	else
	{
		sett->color = 1;
		ft_putstr("\033[0m");
		if (sett->form[sett->p_pct] == '0')
			sett->p_pct = sett->p_pct + 1;
	}
}
