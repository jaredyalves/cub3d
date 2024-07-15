#include "cub3d.h"

#include <libft.h>

static int	count_players(char **map, int height)
{
	int	i;
	int	count;
	size_t	j;

	i = 0;
	count = 0;
	while (i < height)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (ft_strchr("NSWE", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_map(char **map, int height)
{
	int	players_count;

	players_count = count_players(map, height);
	if (height == 0)
		cub3d_exit("Missing map");
	if (players_count == 0)
		cub3d_exit("Missing player");
	if (players_count != 1)
		cub3d_exit("Too many players");
}
