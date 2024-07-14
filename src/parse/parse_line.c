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
	while (colors[i])
	{
		color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
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
	free(trm);
}
