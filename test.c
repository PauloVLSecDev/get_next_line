#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	//pelo que eu entendi a linha abaixo dever ser feita na main
	int fd = open("read_me.txt", O_RDONLY);
	int	line_size;
	static	char *line;
	if (fd == -1)
		printf("Erro nenhum arquivo encontrado");
	line_size = 1;
	line = (char *)malloc(BUFFER_SIZE * sizeof(char *));
		if(!line)
			return (0);
	while(!ft_strchr(line, '\n') != 0)
	{
		line_size = read(fd, line, BUFFER_SIZE);
	}
	if (line_size > 0)
	{
		line[line_size] = '\0';
		printf("foram lidos %s caracteres de %i\n", line, line_size);
	}
	else if (line_size == 0)
		printf("arquivo lido\n");
	else
		printf("erro ao ler aquivo");
	return (0);
}





