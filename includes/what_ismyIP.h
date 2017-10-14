/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_ismyIP.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:19:55 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/14 19:16:37 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHAT_ISMYID_H
# define WHAT_ISMYID_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"

char	*recupid(char *command);
char	*recupIP(void);
char	*recupnewIP(char *tmp);

#endif
