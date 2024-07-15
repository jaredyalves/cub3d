#include "cub3d.h"

#include <fcntl.h>
#include <unistd.h>

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		cub3d_exit("Missing .cub file");
	if (argc != 2)
		cub3d_exit("Too many arguments");
	if (!has_extension(argv[1], "cub"))
		cub3d_exit("File missing .cub extension");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		cub3d_exit("File does not exist or cannot be opened");
	close(fd);
}
