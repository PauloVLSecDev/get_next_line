/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:38:05 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/11 19:03:07 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	char	*new_line;
	
	if (!*buffer || **buffer == '\0')
		return (NULL);
	new_line = ft_strchr(*buffer, '\n');
	if(new_line)
	{
		line = ft_substr(*buffer, 0, new_line - *buffer + 1);
		temp = ft_strdup(new_line + 1);
		free(*buffer);
		*buffer = temp;
	}
	else 
	{
		line = ft_strdup(*buffer);	
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static char	*read_file(int fd, char **buffer)
{
	char	line[BUFFER_SIZE + 1];
	int	size_read;
	char	*temp;

	
	while (1 <= BUFFER_SIZE)
	{
		size_read = read(fd, line, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		if (size_read == 0)
			break;
		line[size_read] = '\0';
		temp = ft_strjoin(*buffer, line);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(line, '\n'))
			break;
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	read_file(fd, &buffer);
	new_line = extract_line(&buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (new_line);
}

// int	main(int argc, char *argv[])
// {
// 	char	*line; 
// 	int	fd;

// 	if (argc < 2)
// 		return (printf("without fd"));
// 	// fd = open(argv[1], O_RDONLY);
// 	fd = 5;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	close(fd);
// 	return (0);
// }
