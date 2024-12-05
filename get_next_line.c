/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/05 16:17:27 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if(!buffer)
		return (NULL);
}

char	*read_file(int fd, char *buffer)
{
	char	*line;
	int	size_read;

	size_read = 1;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char *));
	line = (char *)malloc(BUFFER_SIZE * sizeof(char *));
	if(!buffer)
		return (NULL);
	while(read_file > 0)
	{
		size_read = read(fd, line, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(line);
			return (NULL);
		}
		line[size_read] = '\0';
		if(ft_strchr(line, '\n'))
			break;
	}
	line[size_read] = '\0';
	return (line);
}

int	main(void)
{
	int fd = open("read_me.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("quantidade de linhas %s", line);
	
}
