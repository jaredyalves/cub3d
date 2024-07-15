#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

static void	parse_texture(char *str, char **texture)
{
	if (*texture)
	{
		free(str - 3);
		cub3d_exit("Error\nOne or more textures are duplicated\n");
	}
	*texture = ft_strtrim(str, BLANKS);
}

static void	parse_color(char *str, int color[3])
{
	int		i;
	char	**colors;

	if (*color != -1)
	{
		free(str - 2);
		cub3d_exit("Error\nOne or more colors are duplicated\n");
	}
	colors = ft_split(str, ',');
	if (!colors)
		cub3d_exit("Error\nMemory allocation failed\n");
	i = 0;
	while (colors[i])
	{
		if (i < 3)
			color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
	if (i > 3)
	{
		free(str - 2);
		cub3d_exit("Error\nFloor and Ceiling needs exactly 3 colors each\n");
	}
}

static void	parse_map(char *str)
{
	int			i;
	t_config	*cfg;
	char		**map;

	i = -1;
	cfg = get_config();
	cfg->map_height += 1;
	map = (char **)ft_calloc(sizeof(char *), cfg->map_height);
	if (!map)
		cub3d_exit("Error\nMemory allocation failed\n");
	while (++i < cfg->map_height - 1)
		map[i] = cfg->map[i];
	map[cfg->map_height - 1] = ft_strtrim(str, "\n");
	free(cfg->map);
	cfg->map = map;
}

void	parse_line(char *line)
{
	t_config	*cfg;
	char		*trm;

	cfg = get_config();
	trm = ft_strtrim(line, BLANKS);
	if (!ft_strncmp(trm, "NO ", 3))
		parse_texture(trm + 3, &cfg->n_texture);
	else if (!ft_strncmp(trm, "SO ", 3))
		parse_texture(trm + 3, &cfg->s_texture);
	else if (!ft_strncmp(trm, "WE ", 3))
		parse_texture(trm + 3, &cfg->w_texture);
	else if (!ft_strncmp(trm, "EA ", 3))
		parse_texture(trm + 3, &cfg->e_texture);
	else if (!ft_strncmp(trm, "F ", 2))
		parse_color(trm + 2, cfg->f_color);
	else if (!ft_strncmp(trm, "C ", 2))
		parse_color(trm + 2, cfg->c_color);
	else if (ft_strchr(trm, '0') || ft_strchr(trm, '1'))
		parse_map(line);
	free(trm);
}
