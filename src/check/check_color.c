#include "cub3d.h"

void	check_color(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			cub3d_exit("Missing one or more colors");
		if (color[i] < 0 || color[i] > 255)
			cub3d_exit("Colors must have a value of 0 to 255");
		i++;
	}
}
