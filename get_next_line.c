/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/08 19:23:37 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
char	*ft_freeall(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(buffer);
	return (temp);
}
*/

char	*read_file(int fd, char *remaining)
{
	char	*line;
	int	size_read;

	if(!remaining)
		remaining = (char *)malloc(BUFFER_SIZE);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	size_read = 1;
	if(!line)
	{
		free(line);
		return(NULL);
	}
	while(size_read > 0)
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
//	remaining = ft_freeall(line, remaining);
	line[size_read] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
//	line = read_line(&buffer);
	if(!buffer)
		return (NULL);
	return(buffer);
}

int main(int argc, char **argv)
{
    char *line;
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

