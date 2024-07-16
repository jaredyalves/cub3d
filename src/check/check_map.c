/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:13 by jcapistr          #+#    #+#             */
/*   Updated: 2024/07/16 14:48:13 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <libft.h>

static int	count_players(char **map, int height)
{
	int			i;
	size_t		j;
	t_config	*cfg;

	i = 0;
	cfg = get_config();
	while (i < height)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				cfg->player_y = i;
				cfg->player_x = j;
				cfg->player_direction = map[i][j];
				cfg->player_count++;
			}
			j++;
		}
		i++;
	}
	return (cfg->player_count);
}

static int	flood_fill(int row, int col, int rows, int cols)
{
	t_config	*cfg;
	int			valid;

	cfg = get_config();
	if (!(row >= 0 && row < rows && col >= 0 && col < cols))
		return (1);
	if (cfg->map[row][col] == '1' || cfg->map[row][col] == '#')
		return (1);
	if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1)
		return (0);
	if (ft_strchr(" ", cfg->map[row][col]) == NULL)
		cfg->map[row][col] = '#';
	else
		return (0);
	valid = 1;
	valid &= flood_fill(row + 1, col, rows, cols);
	valid &= flood_fill(row - 1, col, rows, cols);
	valid &= flood_fill(row, col + 1, rows, cols);
	valid &= flood_fill(row, col - 1, rows, cols);
	valid &= flood_fill(row + 1, col + 1, rows, cols);
	valid &= flood_fill(row - 1, col - 1, rows, cols);
	valid &= flood_fill(row + 1, col - 1, rows, cols);
	valid &= flood_fill(row - 1, col + 1, rows, cols);
	return (valid);
}

static int	is_map_valid(char **map, int height)
{
	int	i;
	int	j;
	int	width;

	i = 1;
	width = ft_strlen(map[i]);
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == '0')
				if (!flood_fill(i, j, height, width))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	convert_back_to_zero(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '#')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_map(char **map, int height)
{
	int	players_count;

	if (height == 0)
		cub3d_exit("Missing map");
	players_count = count_players(map, height);
	if (players_count == 0)
		cub3d_exit("Missing player");
	if (players_count != 1)
		cub3d_exit("Too many players");
	if (!is_map_valid(map, height))
		cub3d_exit("Map is not valid");
	convert_back_to_zero(map, height);
}
