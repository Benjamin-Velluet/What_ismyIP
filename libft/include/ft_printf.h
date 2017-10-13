/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:30:56 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:34:05 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct	s_flags
{
	int			s_zero;
	int			s_sharp;
	int			s_space;
	int			s_plus;
	int			s_minus;
	int			s_point;
}				t_flags;

typedef struct	s_storage
{
	uintmax_t	i_ap;
	intmax_t	d_ap;
	char		c_ap;
	char		*s_ap;
	wchar_t		*w_ap;
}				t_storage;

typedef enum	e_speflags
{
	NONE, h, hh, l, ll, j, z
}				t_speflags;

typedef struct	s_setting
{
	const char	*form;
	int			p_pct;
	char		conv;
	int			print;
	char		error;
	int			color;
	t_storage	*stor;
	t_flags		*flag;
	t_speflags	sflag;
}				t_setting;

int				ft_printf(const char *format, ...);

int				increment(int nbr, int reset);
int				verif_signe(t_setting *sett);
void			flag_init(t_setting *sett);
void			decrypt(t_setting *sett, va_list ap);

int				number(t_setting *sett);

void			sharp(t_setting *sett);
void			flag_match(t_setting *sett);
int				res_sort(t_setting *sett);

char			*conv_x(t_setting *sett);
char			*conv_o(t_setting *sett);
char			*conv_u(t_setting *sett);
char			*conv_d(t_setting *sett);
char			*conv_b(t_setting *sett);

int				verif_point(t_setting *sett, int on);

int				calcul_asous(t_setting *sett);
void			true_print(t_setting *sett);

void			end_space(t_setting *sett, int minus);
void			print_result(t_setting *sett);

int				false_s(t_setting *sett, int asous, int i);
int				true_min_s(t_setting *sett, int i);
int				true_max_s(t_setting *sett, int i);

void			decry_end(t_setting *sett, int p_tmp);
void			decry_other(t_setting *sett, int p_tmp, va_list ap);
void			decry_cs(t_setting *sett, va_list ap, int on);
void			decry_s(t_setting *sett, va_list ap);
void			decry_d_and_i(t_setting *sett, int p_tmp, va_list ap);

void			color(t_setting *sett);

#endif
