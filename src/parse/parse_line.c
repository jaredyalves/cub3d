#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

static void	parse_texture(char *str, char **texture)
{
	*texture = ft_strtrim(str, BLANKS);
}

static void	parse_color(char *str, int color[3])
{
	int		i;
	char	**colors;

	i = 0;
	colors = ft_split(str, ',');
	if (!colors)
		cub3d_exit("Error\nMemory allocation failed\n");
	while (colors[i])
	{
		color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
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
