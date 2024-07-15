#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	find_max_length(char **map, int height)
{
	int		i;
	size_t	len;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

static void	normalize_map(char **map, int height)
{
	int		i;
	size_t	len;
	size_t	max_len;
	char	*line;

	i = 0;
	max_len = find_max_length(map, height);
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len < max_len)
		{
			line = (char *)ft_calloc(sizeof(char), max_len + 1);
			ft_strlcpy(line, map[i], len + 1);
			ft_memset(line + len, ' ', max_len - len);
			free(map[i]);
			map[i] = line;
		}
		i++;
	}
}

void	parse_file(char *filename)
{
	t_config	*cfg;
	int			fd;

	cfg = get_config();
	fd = open(filename, O_RDONLY);
	while (1)
	{
		cfg->p_line = get_next_line(fd);
		if (!cfg->p_line)
			break ;
		parse_line(cfg->p_line);
		free(cfg->p_line);
		cfg->p_line = NULL;
	}
	close(fd);
	normalize_map(cfg->map, cfg->map_height);
}
