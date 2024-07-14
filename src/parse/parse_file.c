#include "cub3d.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line);
		free(line);
	}
	close(fd);
}
