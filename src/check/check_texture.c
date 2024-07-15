#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

void	check_texture(char *texture)
{
	int	fd;

	if (!texture)
		cub3d_exit("Missing one or more textures");
	if (!has_extension(texture, "xpm"))
		cub3d_exit("Missing .xpm extension on one or more textures");
	if (ft_strchr(texture, ' ') || ft_strchr(texture, '\t'))
		cub3d_exit("Invalid syntax on one or more textures");
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		cub3d_exit("One or more textures doesn't exist or cannot be opened");
	close(fd);
}
