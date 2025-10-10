/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:19:11 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 17:19:12 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

#define DEFAULT_FILE_CONTAIN { .p = {0}, .fd = -1, .read_f = 0, .i = 0, .atn = false }

typedef struct s_file
{
    char p[BUFFER_SIZE + 1];
    int fd;
    int	read_f;
    int i;
    bool atn;
} t_file;

extern  t_file g_file;

char	*get_next_line(int fd);

bool	ft_strchr(char *s);


int	len_etb();
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

void	ft_bzeor(char *p,int l);


#endif