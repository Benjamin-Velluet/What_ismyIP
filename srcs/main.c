/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:22:20 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/13 22:48:33 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

static char		*recupip(char *str)
{
	int			c;
	FILE		*sortie = popen("curl ifconfig.me", "r");
	int			i;

	i = 0;
	if(sortie == NULL)
	{
		perror("Erreur popen ");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(sortie)) != EOF)
	{
		str[i] = c;
		i++;
	}
	pclose(sortie);
	return (str);
}

int				main(void)
{
	char	*ip;

	ip = ft_memalloc(17);
	ip = recupip(ip);
	system("curl -u mendtechwj:password -T ip.txt ftp://ftp.cluster007.ovh.net:21/www/priver/ip/");
	return (0);
}
