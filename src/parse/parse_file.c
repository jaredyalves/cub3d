#include "cub3d.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_file(t_config *config, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(config, line);
		free(line);
		line = NULL;
	}
	close(fd);
}
