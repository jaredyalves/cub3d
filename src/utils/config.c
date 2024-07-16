/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:13 by jcapistr          #+#    #+#             */
/*   Updated: 2024/07/16 14:48:13 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

t_config	*get_config(void)
{
	static t_config	config;

	return (&config);
}

void	init_config(void)
{
	int			i;
	t_config	*cfg;

	i = 0;
	cfg = get_config();
	cfg->parsing_map = 0;
	cfg->parsing_done = 0;
	cfg->p_line = NULL;
	cfg->p_trim = NULL;
	cfg->n_texture = NULL;
	cfg->s_texture = NULL;
	cfg->w_texture = NULL;
	cfg->e_texture = NULL;
	while (i < 3)
	{
		cfg->f_color[i] = -1;
		cfg->c_color[i] = -1;
		i++;
	}
	cfg->map = NULL;
	cfg->map_height = 0;
	cfg->player_count = 0;
}

void	free_config(void)
{
	int			i;
	t_config	*cfg;

	i = 0;
	cfg = get_config();
	free(cfg->p_line);
	free(cfg->p_trim);
	free(cfg->n_texture);
	free(cfg->s_texture);
	free(cfg->w_texture);
	free(cfg->e_texture);
	while (i < cfg->map_height)
		free(cfg->map[i++]);
	free(cfg->map);
}
