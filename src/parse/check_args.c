#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	has_cub_extension(const char *filename)
{
	const char	*ext = ft_strrchr(filename, '.');

	return (ext && ft_strncmp(ext, ".cub", 5) == 0);
}

void	check_args(const int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nThe program requires exactly one argument\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!has_cub_extension(argv[1]))
	{
		ft_putstr_fd("Error\nThe file must have a .cub extension\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nThe file does not exist or cannot be opened\n", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
