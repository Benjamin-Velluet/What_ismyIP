/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_ismyIP.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:19:55 by bvelluet          #+#    #+#             */
/*   Updated: 2017/10/24 11:52:31 by bvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHAT_ISMYID_H
# define WHAT_ISMYID_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>

# define BUFF_SIZE 1

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_error(char *error);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memalloc(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);

char				*recupid(char *command);
char				*recupip(void);
char				*recupnewip(char *tmp);

#endif
