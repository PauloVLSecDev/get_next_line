/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/09 16:40:23 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extract_line(char **buffer)
{
	char	*new_line;

	new_line = ft_strchr(*buffer, '\n');
	
	return (line)
}

char	*read_file(int fd, char **buffer)
{
	char	line[BUFFER_SIZE + 1];
       	int	size_read;
       	char	*temp; 

	size_read = 1;
	while(size_read > 0)
	{
		size_read = read(fd, line, BUFFER_SIZE);
		if(size_read == -1)
		{
			free(line);
			return (NULL);
		}
		line[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(*buffer, line);
		free(buffer);
		*buffer = temp;
		if(ft_strchr(line, '\n'))
			break;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(fd, &buffer);
	if(!buffer)
		return (NULL);
	return (extract_line(&buffer));
}

int	main(int argc, char *argv[])
{
	char	*line; 
	int	fd;

	if (argc < 2)
		return (printf("without fd"));
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd))!= NULL) 
	{
		printf("%s", line);
		free(line);
	}
}
