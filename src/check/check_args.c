#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("The program requires exactly one argument", 2);
		exit(EXIT_FAILURE);
	}
	if (!has_extension(argv[1], "cub"))
	{
		ft_putstr_fd("The file must have a .cub extension", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("The file does not exist or cannot be opened", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
