#include "cub3d.h"

void	check_config(void)
{
	t_config	*cfg;

	cfg = get_config();
	check_texture(cfg->n_texture);
	check_texture(cfg->s_texture);
	check_texture(cfg->w_texture);
	check_texture(cfg->e_texture);
	check_color(cfg->f_color);
	check_color(cfg->c_color);
	check_map(cfg->map, cfg->map_height);
}
