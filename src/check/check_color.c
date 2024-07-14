#include "cub3d.h"
void check_color(int color[3])
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			cub3d_exit("Error\nMissing one or more colors\n");
		if (color[i] < 0)
			cub3d_exit("Error\nOne or more colors have negative value\n");
		i++;
	}
}
