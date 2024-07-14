#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

void	check_texture(char *texture)
{
	int	fd;

	if (!texture)
		cub3d_exit("Error\nMissing one or more textures\n");
	if (!has_extension(texture, "xpm"))
		cub3d_exit("Error\nMissing .xpm extension on one or more textures\n");
	if (ft_strchr(texture, ' ') || ft_strchr(texture, '\t'))
		cub3d_exit("Error\nInvalid syntax on one or more textures\n");
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		cub3d_exit("One or more textures doesn't exist or cannot be opened\n");
	}
	close(fd);
}
