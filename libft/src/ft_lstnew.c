/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:09:39 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 18:01:17 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list	*new_element;

	if (!(new_element = malloc(sizeof(*new_element))))
		ft_error("Malloc Allocation ---> ft_lstnew");
	if (!content)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		if (!(new_element->content = malloc(content_size * sizeof(char))))
			ft_error("Malloc Allocation ---> ft_lstnew");
		ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
