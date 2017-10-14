/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 18:52:43 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/14 19:24:31 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

static char		*prep_command(char *host, char *user, char *pass)
{
	char		*command;

	command = ft_strnew(20 + ft_strlen(host) + ft_strlen(user) + ft_strlen(pass));
	command = ft_strcat(command, "curl -u ");
	command = ft_strcat(command, user);
	command = ft_strcat(command, ":");
	command = ft_strcat(command, pass);
	command = ft_strcat(command, " -T ip.txt ");
	command = ft_strcat(command, host);
	free(host);
	free(user);
	free(pass);
	return (command);
}

char			*recupid(char *command)
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
	if (close(fd) == -1)
		ft_error("Closing the file users.id");
	command = prep_command(host, user, pass);
	return (command);
}

char			*recupIP(void)
{
	int			fd;
	char		*str;

	if ((fd = open("./ip.txt", O_RDONLY)) == -1)
		ft_error("Missing ip.txt file");
	if (!get_next_line(fd, &str))
		ft_error("Missing IP in ip.txt");
	if (close(fd) == -1)
		ft_error("Closing the file ip.txt");
	return (str);
}

char			*recupnewIP(char *tmp)
{
	FILE		*sortie = popen("curl ifconfig.me", "r");
	int			i;
	char		*str;

	i = 0;
	if(!sortie)
		ft_error("Unable to recover IP");
	while ((tmp[i] = (char)fgetc(sortie)) != EOF)
		i++;
	str = ft_strnew(i - 1);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	free(tmp);
	pclose(sortie);
	return (str);
}
