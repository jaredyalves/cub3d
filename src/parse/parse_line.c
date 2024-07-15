#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

static void	parse_texture(char *str, char **texture)
{
	if (*texture)
		return (free(str - 3), cub3d_exit("Duplicated texture"));
	*texture = ft_strtrim(str, BLANKS);
}

static void	parse_color(char *str, int color[3])
{
	int		i;
	char	**colors;

	if (color[0] != -1 || color[1] != -1 || color[2] != -1)
		return (free(str - 2), cub3d_exit("Duplicated color"));
	colors = ft_split(str, ',');
	if (!colors)
		cub3d_exit("Memory allocation failed");
	i = 0;
	while (colors[i])
	{
		if (i < 3)
			color[i] = cub3d_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
	if (i > 3 || *(str + ft_strlen(str) - 1) == ',')
		return (free(str - 2), cub3d_exit("Invalid color syntax"));
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
		cub3d_exit("Memory allocation failed");
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
