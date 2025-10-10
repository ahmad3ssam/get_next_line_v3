/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:16:57 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 18:55:43 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct s_file g_file = DEFAULT_FILE_CONTAIN;


void set_data(int fd)
{
	// printf("ih");
	g_file.read_f = read(fd, g_file.p, BUFFER_SIZE);
	g_file.i = 0;
	g_file.p[g_file.read_f] = '\0';
	g_file.fd = fd;
	g_file.atn = false;

}

char *line()
{
	char *p;
	int len =len_etb();

	p = malloc(len + 1);
	if(!p)
		return(NULL);
	g_file.atn = ft_strchr(p);
	while(!g_file.atn)
	{
		set_data(g_file.fd);
		if(g_file.read_f == -1)
			return(NULL);
		p = ft_strjoin(p,g_file.p);
	}
	return(p);
}

char	*get_next_line(int fd)
{
	char			*ptr;
	// static char p[BUFFER_SIZE + 1];

	
	if (fd <= 2 || BUFFER_SIZE <= 0)
		return (NULL);

	if (g_file.fd != fd || g_file.i == g_file.read_f)
		set_data(fd);

	if(g_file.read_f <= -1)
		return (NULL);
	ptr = line();
	// printf("%d == %d\n",g_file.i,g_file.read_f);
	return (ptr);
}

int	main(void)
{
	int i = 0;
	int fd = open("ahmad.txt", O_RDONLY);
	//#define DEFAULT_FILE_CONTAIN { .p = {0}, .fd = -1, .read_f = 0, .i = 0, .atn = false }

	printf("%s,%d,%d,%d,%d\n",g_file.p,g_file.fd,g_file.read_f,g_file.i,g_file.atn);
	while (i < 9)
	{
		char *p = get_next_line(fd);
		printf("line %d %s",i,p);
		free(p);
		i++;
	}
	printf("%s,%d,%d,%d,%d\n",g_file.p,g_file.fd,g_file.read_f,g_file.i,g_file.atn);

}