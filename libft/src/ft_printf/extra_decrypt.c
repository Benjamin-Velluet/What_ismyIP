/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_decrypt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:58:52 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:12 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	decry_d_and_i(t_setting *sett, int p_tmp, va_list ap)
{
	sett->conv = 'd';
	if (sett->sflag == ll || sett->form[p_tmp] == 'D')
		sett->stor->d_ap = va_arg(ap, long long);
	else if (sett->sflag == hh)
		sett->stor->d_ap = (signed char)va_arg(ap, int);
	else if (sett->sflag == h)
		sett->stor->d_ap = (short)va_arg(ap, int);
	else if (sett->sflag == l)
		sett->stor->d_ap = va_arg(ap, long int);
	else if (sett->sflag == j)
		sett->stor->d_ap = va_arg(ap, intmax_t);
	else if (sett->sflag == z)
		sett->stor->d_ap = va_arg(ap, ssize_t);
	else if (sett->sflag == NONE)
		sett->stor->d_ap = va_arg(ap, int);
}

void	decry_s(t_setting *sett, va_list ap)
{
	if (sett->sflag == l)
	{
		sett->conv = 'S';
		sett->stor->w_ap = (wchar_t *)va_arg(ap, char *);
		if (sett->stor->w_ap == NULL)
		{
			sett->conv = 's';
			sett->stor->s_ap = "(null)";
		}
	}
	else
	{
		sett->conv = 's';
		sett->stor->s_ap = va_arg(ap, char *);
	}
}

void	decry_cs(t_setting *sett, va_list ap, int on)
{
	if (on == 1)
	{
		if (sett->sflag == l)
		{
			sett->conv = 'C';
			sett->stor->i_ap = va_arg(ap, unsigned int);
		}
		else
		{
			sett->conv = 'c';
			sett->stor->c_ap = (char)va_arg(ap, int);
		}
	}
	else
	{
		sett->conv = 'S';
		sett->stor->w_ap = (wchar_t *)va_arg(ap, char *);
		if (sett->stor->w_ap == NULL)
		{
			sett->conv = 's';
			sett->stor->s_ap = "(null)";
		}
	}
}

void	decry_other(t_setting *sett, int p_tmp, va_list ap)
{
	if (sett->sflag == l || sett->form[p_tmp] == 'U' ||
			sett->form[p_tmp] == 'B' || sett->form[p_tmp] == 'O' ||
			sett->form[p_tmp] == 'p' || sett->form[p_tmp] == 'C')
		sett->stor->i_ap = va_arg(ap, unsigned long int);
	else if (sett->sflag == hh)
		sett->stor->i_ap = (unsigned char)va_arg(ap, int);
	else if (sett->sflag == h)
		sett->stor->i_ap = (unsigned short)va_arg(ap, int);
	else if (sett->sflag == ll)
		sett->stor->i_ap = va_arg(ap, unsigned long long int);
	else if (sett->sflag == j)
		sett->stor->i_ap = va_arg(ap, uintmax_t);
	else if (sett->sflag == z)
		sett->stor->i_ap = va_arg(ap, size_t);
	else if (sett->sflag == NONE)
		sett->stor->i_ap = va_arg(ap, unsigned int);
}

void	decry_end(t_setting *sett, int p_tmp)
{
	if (sett->form[p_tmp] == 'C')
		sett->conv = 'C';
	else if (sett->form[p_tmp] == 'x' || sett->form[p_tmp] == 'X')
		sett->conv = sett->form[p_tmp];
	else if (sett->form[p_tmp] == 'p')
	{
		sett->conv = 'p';
		sett->flag->s_sharp = 1;
	}
	else if (ft_strchr("oub%", ft_tolower(sett->form[p_tmp])))
		sett->conv = ft_tolower(sett->form[p_tmp]);
}
