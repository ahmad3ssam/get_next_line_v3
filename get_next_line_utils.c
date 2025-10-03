/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:17:03 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 18:49:20 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	ft_strlcat(char *dst, char *src)
{
	size_t len_dest;

	len_dest = ft_strlen(dst);
	while (src[file.i] != '\n' && src[file.i] != '\0')
	{
		dst[len_dest + file.i] = src[file.i];
		file.i++;
	}
	if(src[file.i] == '\n')
	{
		file.ATN = true;
		dst[len_dest + file.i] = '\n';
		file.i++;
	}
	dst[len_dest + file.i] = '\0';
}

void	ft_strlcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i]='\0';
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	len_ETB()
{
	int i = 0;

	while (file.p[file.i + i] != '\n' && file.p[file.i + i] != '\0')
	{
		i++;
	}

	if (file.p[file.i + i] == '\n')
		return (i + 1);
	return (i);
}

bool	ft_strchr(char *s)
{
	int		i;
	i = 0;

	
	while (file.p[file.i] != '\n' && file.p[file.i] != '\0')
	{
		s[i] = file.p[file.i] ;
		file.i++;
		i++;
	}
	if (file.p[file.i] == '\n')
	{
		s[i++] = '\n';
		file.i++;
		file.ATN = true;
	}
	s[i] = '\0';
	return(file.p[file.i - 1] == '\n');
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (s1 && !s2[0])
	{
		file.ATN = true;
		return (s1);
	}
	len = ft_strlen(s1) + len_ETB(s2) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1);
	free(s1);
	ft_strlcat(str, s2);
	return (str);
}

