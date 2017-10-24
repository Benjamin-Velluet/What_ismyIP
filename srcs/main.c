/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:22:20 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:52:42 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

static void		changefile(char *ip)
{
	int			fd;

	system("rm -f ip.txt && touch ip.txt");
	if ((fd = open("./ip.txt", O_WRONLY)) == -1)
		ft_error("Missing ip.txt file");
	ft_putstr_fd(ip, fd);
	if (close(fd) == -1)
		ft_error("Closing the file ip.txt");
	free(ip);
}

int				main(void)
{
	char	*newip;
	char	*command;
	char	*ip;

	newip = ft_memalloc(16);
	ip = recupip();
	command = NULL;
	newip = recupnewip(newip);
	if (ft_strcmp(ip, newip))
	{
		changefile(newip);
		command = recupid(command);
		system(command);
	}
	return (0);
}
