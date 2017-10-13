/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 10:26:26 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:11:38 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void		sort(t_setting *sett, va_list ap)
{
	int			minus;

	if (sett->form[sett->p_pct])
	{
		flag_init(sett);
		flag_match(sett);
		decrypt(sett, ap);
		minus = res_sort(sett);
		print_result(sett);
		end_space(sett, minus);
		va_end(ap);
	}
}

static int		end_ft_printf(t_setting *sett)
{
	int			result;

	result = increment(0, 0);
	increment(0, 1);
	if (sett->color == 1)
		ft_putstr("\033[0m");
	free(sett->stor);
	free(sett->flag);
	free(sett);
	return (result);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_setting	*sett;
	int			result;

	if (!format)
		return (-1);
	if (!(sett = malloc(sizeof(t_setting))))
		ft_error("Malloc Allocation ---> ft_printf");
	sett->form = format;
	sett->p_pct = 0;
	sett->color = 0;
	if (!(sett->stor = malloc(sizeof(t_storage))))
		ft_error("Malloc Allocation ---> ft_printf");
	if (!(sett->flag = malloc(sizeof(t_flags))))
		ft_error("Malloc Allocation ---> ft_printf");
	va_start(ap, format);
	while (sett->form[sett->p_pct] != '\0')
	{
		if (verif_signe(sett))
			sort(sett, ap);
	}
	result = end_ft_printf(sett);
	return (result);
}
