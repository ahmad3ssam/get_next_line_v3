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
file_containt file = { .i = 0, .ATN = false, .fd = -1, .read_f = 0, .p = {0} };


void set_data(int fd)
{
	// printf("ih");
	file.read_f = read(fd, file.p, BUFFER_SIZE);
	file.i = 0;
	file.p[file.read_f] = '\0';
	file.fd = fd;
	file.ATN = false;

}

char *line()
{
	char *p;
	int len =len_ETB();

	p = malloc(len + 1);
	if(!p)
		return(NULL);
	file.ATN = ft_strchr(p);
	while(!file.ATN)
	{
		set_data(file.fd);
		// printf("\nfile index %d read %d %d\n",file.i,file.read_f,file.ATN);
		// printf("%s\n",file.p);
		if(file.read_f == -1)
			return(NULL);
		p = ft_strjoin(p,file.p);
	}
	return(p);
}

char	*get_next_line(int fd)
{
	static int		i;
	char			*ptr;

	
	if (fd <= 2 || BUFFER_SIZE <= 0)
		return (NULL);

	if (file.fd != fd)
		set_data(fd);

	if(file.read_f == -1)
		return (NULL);
	ptr = line();

	return (ptr);
}

int	main(void)
{
	int i = 0;
	int fd = open("ahmad.txt", O_RDONLY);

	while (i < 6)
	{
		char *p = get_next_line(fd);
		printf("line %d %s",i,p);
		i++;
	}
}