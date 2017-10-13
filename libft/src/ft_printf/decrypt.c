/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:30:40 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:03 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		decrypt(t_setting *sett, va_list ap)
{
	int		p_tmp;

	p_tmp = sett->p_pct;
	while ((sett->form[p_tmp] >= '0' && sett->form[p_tmp] <= '9') ||
			ft_strchr("hljz.", sett->form[p_tmp]))
		p_tmp++;
	if (sett->form[p_tmp] == 'c')
		decry_cs(sett, ap, 1);
	else if (sett->form[p_tmp] == 's')
		decry_s(sett, ap);
	else if (sett->form[p_tmp] == 'S')
		decry_cs(sett, ap, 0);
	else if (ft_tolower(sett->form[p_tmp]) == 'd' ||
			ft_tolower(sett->form[p_tmp]) == 'i')
		decry_d_and_i(sett, p_tmp, ap);
	else if (ft_strchr("UubBOopCxX%", sett->form[p_tmp]) == 0)
	{
		sett->conv = '!';
		sett->error = sett->form[p_tmp];
	}
	else
		decry_other(sett, p_tmp, ap);
	decry_end(sett, p_tmp);
}
