#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

static void	parse_texture(char *str, char **texture)
{
	if (*texture)
		cub3d_exit("Duplicated texture");
	*texture = ft_strtrim(str, BLANKS);
}

static void	parse_color(char *str, int color[3])
{
	int		i;
	char	**colors;

	if (color[0] != -1 || color[1] != -1 || color[2] != -1)
		cub3d_exit("Duplicated color");
	colors = ft_split(str, ',');
	if (!colors)
		cub3d_exit("Memory allocation failed");
	i = 0;
	while (colors[i])
	{
		if (i < 3)
			color[i] = cub3d_atoi(colors[i], colors, i);
		free(colors[i++]);
	}
	free(colors);
	if (i > 3 || *(str + ft_strlen(str) - 1) == ',')
		cub3d_exit("Invalid color syntax");
}

static void	parse_map_line(char *str)
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
	cfg->parsing_map = 1;
}

static void	verify_parsing(void)
{
	t_config	*cfg;

	cfg = get_config();
	if (cfg->parsing_map == 1)
	{
		if (!*cfg->p_trim)
		{
			cfg->parsing_map = 0;
			cfg->parsing_done = 1;
		}
	}
}

void	parse_line(char *line)
{
	t_config	*cfg;

	cfg = get_config();
	cfg->p_trim = ft_strtrim(line, BLANKS);
	verify_parsing();
	if (cfg->parsing_done && *cfg->p_trim)
		cub3d_exit("Map is not the last");
	if (!ft_strncmp(cfg->p_trim, "NO ", 3))
		parse_texture(cfg->p_trim + 3, &cfg->n_texture);
	else if (!ft_strncmp(cfg->p_trim, "SO ", 3))
		parse_texture(cfg->p_trim + 3, &cfg->s_texture);
	else if (!ft_strncmp(cfg->p_trim, "WE ", 3))
		parse_texture(cfg->p_trim + 3, &cfg->w_texture);
	else if (!ft_strncmp(cfg->p_trim, "EA ", 3))
		parse_texture(cfg->p_trim + 3, &cfg->e_texture);
	else if (!ft_strncmp(cfg->p_trim, "F ", 2))
		parse_color(cfg->p_trim + 2, cfg->f_color);
	else if (!ft_strncmp(cfg->p_trim, "C ", 2))
		parse_color(cfg->p_trim + 2, cfg->c_color);
	else if (ft_strchr(cfg->p_trim, '0') || ft_strchr(cfg->p_trim, '1'))
		parse_map_line(line);
	free(cfg->p_trim);
	cfg->p_trim = NULL;
}
