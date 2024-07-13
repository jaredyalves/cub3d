#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	char	**map;
	int		map_height;

}			t_config;

// Init
void		init_config(t_config *config);

// Parse
void		check_args(const int argc, char **argv);
void		parse_file(t_config *config, const char *filename);
void		parse_line(t_config *config, char *line);

#endif
