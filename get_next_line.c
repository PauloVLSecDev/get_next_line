/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/05 19:45:16 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_freeall(int fd, char *buffer)
{
	char	*temp;

	temp = strjoin(line, buffer)
	free(buffer);
	
}
char	*read_file(int fd, char *remaining)
{
	char	*line;
	int	size_read;
	if(!remaining)
		remaining = (char *)malloc(BUFFER_SIZE);
	size_read = 1;
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!line)
		free(line);
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
	buffer = ft_free(line, remaining);
	line[size_read] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE];
	char	*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if(!buffer)
		return (NULL);
	return(buffer);
} 
int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i = 1;

	while (i < argc)
    {
		fd = open(argv[i], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		i++;
    }
	return 0;
}
