#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	int fd;
	int size;
	char buffer[BUFFER_SIZE + 1];

	fd = open("gnl.c", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break;
		buffer[size] = '\0';
		printf("%s", buffer);
	}
	return (0);
}