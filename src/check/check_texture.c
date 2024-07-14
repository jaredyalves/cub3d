#include "cub3d.h"
#include "libft.h"

void	check_texture(char *texture)
{
	if (!texture)
		cub3d_exit("Error\nMissing one or more textures\n");
	if (!has_extension(texture, "xpm"))
		cub3d_exit("Error\nMissing .xpm extension on one or more textures\n");
	if (ft_strchr(texture, ' ') || ft_strchr(texture, '\t'))
		cub3d_exit("Error\nInvalid syntax on one or more textures\n");
}
