/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:46:51 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:02:15 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*book;

	if (!(book = malloc(size * sizeof(size_t))))
		ft_error("Malloc Allocation ---> ft_memalloc");
	ft_bzero(book, size);
	return (book);
}
