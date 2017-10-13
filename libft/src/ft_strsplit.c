/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:19 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/11 17:07:33 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static const char	*ft_next(const char *s1, char c, int next)
{
	if (next)
		while ((*s1 != '\0') && (*s1 == c))
			s1++;
	else
		while ((*s1 != '\0') && (*s1 != c))
			s1++;
	return (s1);
}

static int			ft_leng(const char *s1, char c)
{
	int		i;

	i = 0;
	while (*s1 != '\0')
	{
		s1 = ft_next(s1, c, 1);
		if (*s1 != '\0')
		{
			i++;
			s1 = ft_next(s1, c, 0);
		}
	}
	return (i);
}

static char			**ft_sup(char **sup, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(sup[i]);
	free(sup);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**exit;
	int			i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	if (!(exit = (char**)malloc(sizeof(char*) * (ft_leng(s, c) + 1))))
		ft_error("Malloc Allocation --> ft_strsplit");
	i = 0;
	while (*s != '\0')
	{
		s = ft_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_next(s, c, 0);
			exit[i] = ft_strsub(s, 0, next - s);
			if (exit[i] == NULL)
				return (ft_sup(exit, i));
			i++;
			s = next;
		}
	}
	exit[i] = NULL;
	return (exit);
}
