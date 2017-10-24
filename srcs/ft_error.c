/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:37:16 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:37:06 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

void	ft_error(char *error)
{
	ft_putstr_fd("\x1b[31mERROR: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd("\x1b[0m", 2);
	exit(-1);
}
