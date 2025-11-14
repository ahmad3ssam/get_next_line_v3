/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:48:46 by ahhammad          #+#    #+#             */
/*   Updated: 2025/11/14 23:18:38 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strlen(char *s);
char*	ft_strjoin( char *s1, char *s2);
void	ft_strlcpy(char *dest, const char *src);
void	ft_strlcat(char *dst, char *src);
int     search_nl(char *buffer);
char    *get_line(char **re_data,char *buffer); 
int     set_data(char **re_data, char *buffer,int fd);
char	*get_next_line(int fd);
// char    *free_bufffer(char *p);
#endif