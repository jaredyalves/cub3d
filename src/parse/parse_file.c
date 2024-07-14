#include "cub3d.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_file(char *filename)
{
	t_config	*config;
	int			fd;

	config = get_config();
	fd = open(filename, O_RDONLY);
	while (1)
	{
		config->p_line = get_next_line(fd);
		if (!config->p_line)
			break ;
		parse_line(config->p_line);
		free(config->p_line);
		config->p_line = NULL;
	}
	close(fd);
}
