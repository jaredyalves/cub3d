#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

void	parse_texture(char *line, char **texture)
{
	*texture = ft_strdup(ft_strtrim(line, " \n"));
}

void	parse_color(char *line, int color[3])
{
	int		i;
	char	**colors;

	i = 0;
	colors = ft_split(line, ',');
	while (colors[i])
	{
		color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
}

void	parse_line(t_config *config, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		parse_texture(line + 3, &config->north_texture);
	else if (!ft_strncmp(line, "SO ", 3))
		parse_texture(line + 3, &config->south_texture);
	else if (!ft_strncmp(line, "WE ", 3))
		parse_texture(line + 3, &config->west_texture);
	else if (!ft_strncmp(line, "EA ", 3))
		parse_texture(line + 3, &config->east_texture);
	else if (!ft_strncmp(line, "F ", 2))
		parse_color(line + 2, config->floor_color);
	else if (!ft_strncmp(line, "C ", 2))
		parse_color(line + 2, config->ceiling_color);
}
