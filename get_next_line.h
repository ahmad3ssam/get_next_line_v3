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

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

# define BUFFER_SIZE 3

typedef struct {
    char p[BUFFER_SIZE + 1];
    int fd;
    size_t	read_f;
    int i;
    bool ATN;
}file_containt;

extern file_containt file;
// static file_containt file;

// file_containt* get_file(void) {
//     return &file;
// }

char	*get_next_line(int fd);
// char *get_next_line_utils(char *p,int rows);
bool	ft_strchr(char *s);
// char	*ft_strchr(char *c, int *len);

int	len_ETB();
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

void	ft_bzeor(char *p,int l);


#endif