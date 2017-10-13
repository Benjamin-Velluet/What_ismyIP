/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:22:20 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/13 23:44:40 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

static char		*recupIP(char *str)
{
	int			c;
	FILE		*sortie = popen("curl ifconfig.me", "r");
	int			i;

	i = 0;
	if(!sortie)
		ft_error("Unable to recover IP");
	while ((c = fgetc(sortie)) != EOF)
	{
		str[i] = c;
		i++;
	}
	pclose(sortie);
	return (str);
}

static char		*recupid(char *command)
{
	int			fd;
	char		*host;
	char		*user;
	char		*pass;

	if ((fd = open("./users.id", O_RDONLY)) == -1)
		ft_error("Missing users.id file");
	if (!get_next_line(fd, &host))
		ft_error("Missing host in users.id");
	if (!get_next_line(fd, &user))
		ft_error("Missing user in users.id");
	if (!get_next_line(fd, &pass))
		ft_error("Missing password in users.id");
	command = ft_strnew(20 + ft_strlen(host) + ft_strlen(user) + ft_strlen(pass));
	command = ft_strcat(command, "curl -u ");
	command = ft_strcat(command, user);
	command = ft_strcat(command, ":");
	command = ft_strcat(command, pass);
	command = ft_strcat(command, " -T ip.txt ");
	command = ft_strcat(command, host);
	return (command);
}

int				main(void)
{
	char	*ip;
	char	*command;

	ip = ft_memalloc(17);
	command = NULL;
	ip = recupIP(ip);
	command = recupid(command);
	system(command);
	return (0);
}
