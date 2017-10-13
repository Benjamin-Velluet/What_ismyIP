/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:02:48 by bvelluet          #+#    #+#             */
/*   Updated: 2017/04/05 16:14:04 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		possition;
	int		recherche;

	possition = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[possition] != '\0')
	{
		recherche = 0;
		while (little[recherche] == big[possition + recherche])
		{
			if (little[recherche + 1] == '\0')
			{
				return ((char *)big + possition);
			}
			recherche++;
		}
		possition++;
	}
	return (NULL);
}
