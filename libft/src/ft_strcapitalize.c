/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:41:47 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:11:19 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_toupper(str[i]) != str[i]) && (!ft_isalnum(str[i - 1])))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
