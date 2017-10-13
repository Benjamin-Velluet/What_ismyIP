/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetogo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:49:36 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:27 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void		fuck_the_norme(t_setting *sett)
{
	if (sett->conv == 's' && sett->print == 1)
	{
		ft_putstr(sett->stor->s_ap);
		increment(ft_strlen(sett->stor->s_ap), 0);
	}
	else if (sett->conv == 'S' && sett->print == 1)
	{
		if (ft_wstrlen(sett->stor->w_ap))
		{
			ft_putstr(ft_wstrtoa(sett->stor->w_ap));
			increment(ft_strlen(ft_wstrtoa(sett->stor->w_ap)), 0);
		}
	}
	else if (sett->conv == '%' && sett->print == 1)
	{
		ft_putchar('%');
		increment(1, 0);
	}
	else if (sett->conv == '!')
	{
		ft_putchar(sett->error);
		increment(1, 0);
	}
	sett->p_pct = sett->p_pct + 1;
}

static void		extra_extra_print(t_setting *sett)
{
	if (sett->conv == 'c' && sett->print == 1)
	{
		if (sett->stor->c_ap == 0)
			ft_putchar('\0');
		else
			ft_putchar(sett->stor->c_ap);
		increment(1, 0);
	}
	else if (sett->conv == 'C' && sett->print == 1)
	{
		if (ft_strlen(ft_wchartoa(sett->stor->i_ap)))
		{
			ft_putstr(ft_wchartoa(sett->stor->i_ap));
			increment(ft_strlen(ft_wchartoa(sett->stor->i_ap)), 0);
		}
		else
		{
			ft_putchar('\0');
			increment(1, 0);
		}
	}
	fuck_the_norme(sett);
}

static void		extra_print(t_setting *sett, int i)
{
	if (sett->conv == 'd' && sett->print == 1)
	{
		if (conv_d(sett)[0] == '-')
		{
			while (conv_d(sett)[i])
			{
				ft_putchar(conv_d(sett)[i]);
				increment(1, 0);
				i++;
			}
		}
		else
		{
			ft_putstr(conv_d(sett));
			increment(ft_strlen(conv_d(sett)), 0);
		}
	}
	else if (sett->conv == 'b' && sett->print == 1)
	{
		ft_putstr(conv_b(sett));
		increment(ft_strlen(conv_b(sett)), 0);
	}
	extra_extra_print(sett);
}

void			print_result(t_setting *sett)
{
	int			i;

	i = 1;
	if ((sett->conv == 'x' || sett->conv == 'p') && sett->print == 1)
	{
		ft_putstr(conv_x(sett));
		increment(ft_strlen(conv_x(sett)), 0);
	}
	else if (sett->conv == 'X' && sett->print == 1)
	{
		ft_putstr(ft_strupcase(conv_x(sett)));
		increment(ft_strlen(conv_x(sett)), 0);
	}
	else if (sett->conv == 'o' && sett->print == 1)
	{
		ft_putstr(conv_o(sett));
		increment(ft_strlen(conv_o(sett)), 0);
	}
	else if (sett->conv == 'u' && sett->print == 1)
	{
		ft_putstr(conv_u(sett));
		increment(ft_strlen(conv_u(sett)), 0);
	}
	extra_print(sett, i);
}

void			end_space(t_setting *sett, int minus)
{
	int			i;

	i = 0;
	if (sett->flag->s_minus == 1)
	{
		while (i < minus)
		{
			ft_putchar(' ');
			increment(1, 0);
			i++;
		}
	}
}
