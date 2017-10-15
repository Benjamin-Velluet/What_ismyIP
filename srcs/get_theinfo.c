/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 18:52:43 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/15 18:12:59 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/what_ismyIP.h"

static char		*prep_command(int fd, char *host, char *path, char *user)
{
	char		*command;
	char		*pass;
	int			len;

	if (!get_next_line(fd, &pass))
		ft_error("Missing password in users.id");
	if (close(fd) == -1)
		ft_error("Closing the file users.id");
	len = ft_strlen(host) + ft_strlen(path) + ft_strlen(user) + ft_strlen(pass);
	command = ft_strnew(21 + len);
	command = ft_strcat(command, "curl -u ");
	command = ft_strcat(command, user);
	command = ft_strcat(command, ":");
	command = ft_strcat(command, pass);
	command = ft_strcat(command, " -T ip.txt ");
	command = ft_strcat(command, host);
	if (path[0] != '/' && host[ft_strlen(host)] != '/')
		command = ft_strcat(command, "/");
	command = ft_strcat(command, path);
	free(host);
	free(user);
	free(pass);
	free(path);
	return (command);
}

char			*recupid(char *command)
{
	int			fd;
	char		*host;
	char		*path;
	char		*user;

	if ((fd = open("./users.id", O_RDONLY)) == -1)
		ft_error("Missing users.id file");
	if (!get_next_line(fd, &host))
		ft_error("Missing host in users.id");
	if (!get_next_line(fd, &path))
		ft_error("Missing path in users.id");
	if (!get_next_line(fd, &user))
		ft_error("Missing user in users.id");
	command = prep_command(fd, host, path, user);
	return (command);
}

char			*recupip(void)
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

char			*recupnewip(char *tmp)
{
	FILE		*sortie;
	int			i;
	char		*str;

	i = 0;
	if (!(sortie = popen("curl ifconfig.me", "r")))
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
