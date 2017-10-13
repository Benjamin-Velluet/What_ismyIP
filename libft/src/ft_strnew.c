/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:54:24 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:05:04 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char			*book;
	unsigned int	i;

	i = 0;
	if (!(book = malloc(size + 1 * sizeof(char))))
		ft_error("Malloc Allocation ---> ft_strnew");
	while (i <= size)
	{
		book[i] = '\0';
		i++;
	}
	return (book);
}
