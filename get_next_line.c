/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/05 18:37:51 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *buffer)
{
	char	*line;
	int	size_read;

	size_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if(!buffer)
		return (NULL);
	while(read_file > 0)
	{
		size_read = read(fd, line, BUFFER_SIZE + 1);
		if (size_read == -1)
		{
			free(line);
			return (NULL);
		}
		if(ft_strchr(line, '\n'))
			break;
	}
	line[size_read] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if(!buffer)
		return (NULL);
	return(buffer);
}

int	main(void)
{
	int fd = open("read_me.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	
}
