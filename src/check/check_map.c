#include "cub3d.h"

void	check_map(char **map, int height)
{
	(void)map;
	if (height == 0)
		cub3d_exit("Missing map");
}
