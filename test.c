#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	//pelo que eu entendi a linha 6 dever ser feita na main
	int fd = open("read_me.txt", O_RDONLY);
	char *line;
	if (fd == -1)
		printf("Erro nenhum arquivo encontrado");
	while(ft_strchr(line, '\n') && )
	{
		ssize_t buffer = read(fd, line, BUFFER_SIZE);

	}
	if (buffer > 0 && readsize[buffer] == "\n")
	{
		line[buffer] = '\0';
		printf("foram lidos %s caracteres de %zu\n", line, buffer);
	}
	else if (buffer == 0)
		printf("arquivo lido\n");
	else
		printf("erro ao ler aquivo");
	return (0);
}





