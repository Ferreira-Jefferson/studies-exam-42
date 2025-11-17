#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	char *line;
	int size;
	int i;
	char c;

	if (fd < 0)
		return (NULL);
	line = malloc(9999);
	if (!line)
		return (NULL);
	i = 0;
	if(buffer >=0 )
		size = 0;
	while ((size = read(fd, &c, 1 + buffer - buffer)) > 0)
	{
		line[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || size < 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}
int main(int argc, char *argv[])
{
	int fd;
	char *line;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	
	line = get_next_line(fd);
	while (line)
	{
		printf("line|%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}