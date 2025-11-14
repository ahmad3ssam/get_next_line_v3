/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:48:18 by ahhammad          #+#    #+#             */
/*   Updated: 2025/11/14 21:48:18 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char    *free_buffer(char *buffer)
// {
//     free(buffer);
//     return (NULL);
// }

int set_data(char **re_data, char *buffer,int fd)
{
    char    *line;
    int     read_f;

    if(!buffer)
    {
        free(buffer);
        free(*re_data);
        return (1);
    }
    read_f= read(fd, buffer, BUFFER_SIZE);
    if(read_f > 0)
    {
        buffer[read_f] = '\0';
        line = ft_strjoin(*re_data, buffer);
    }
    else if(read_f == 0 && re_data)
        line = *re_data;
    else
    {
        free(buffer);
        free(*re_data);
        return (-1);
    }
    *re_data = line;
    free(line);
}

int search_nl(char *buffer)
{
    int i;
    
    i=0;
    while(buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    if(buffer[i] == '\n')
        return(i + 1);
    return (i);
}

int     ft_strlen(char *s)
{
    int len;

    len = 0;
    while(s[len] != '\0')
        len++;
    return(len);
}


char    *get_line(char **re_data,char *buffer)
{
    int len_buff;
    int i;
    char *line;
    
    len_buff = search_nl(buffer);
    i = 0;
    if(!*re_data)
        return(free(buffer),NULL);
    line = *re_data;
    printf("line before get_line:%s\n",buffer);
    // printf("line in get_line:%d\n",ft_strlen(buffer) - len_buff);
    if((ft_strlen(buffer) - len_buff) != 0)
    {
        printf("inside get_line\n");
        printf("len_buff:%d\n",ft_strlen(buffer) - len_buff);
        *re_data = malloc(ft_strlen(buffer) - len_buff);
        if(!*re_data)
            return(free(buffer),NULL);
        printf("re_data allocated in get_line\n");

        while(i < BUFFER_SIZE)
        {
            printf ("buffer[%d]:%c\n",i + len_buff,buffer[i + len_buff]);
            *re_data[i] = buffer[i + len_buff];
            i++;
        }
        printf("re_data allocated in get_line\n");
        *re_data[len_buff + i] = '\0';
    }
    printf("re_data in get_line:%s\n",line);
    return(line);
}

char	*get_next_line(int fd)
{
    static char	*re_data;
    char		*buffer;
    char		*line;
    int         read_f;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
        return (free(re_data),NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    
    if(set_data(&re_data, buffer,fd) == -1)
        return (free(buffer),NULL);
    while(re_data != NULL)
    {
        // printf("re_data in gnl:%s\n",re_data);
        int read_f = read(fd, buffer, BUFFER_SIZE);
        if(read_f > 0)
        {
            buffer[read_f] = '\0';
            re_data = ft_strjoin(re_data, buffer);
        }
        else
        {
            break;  
        }
    }
    line = get_line(&re_data,buffer);
    printf("line in gnl:%s\n",line);
    if(!line)
    {
        free(re_data);
        free(buffer);
        return(line);
    }
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    line = get_next_line(fd);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}