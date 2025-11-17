#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "gnl.h"

int main()
{
	int fd;
	int size;
	char buffer[BUFFER_SIZE + 1];

	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	fd = open("gnl-2.c", 00);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo\n");
		return (1);
	}
	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		printf("%s", buffer);
	}
	close(fd);
	return (0);
}