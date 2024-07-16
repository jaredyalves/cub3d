/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:13 by jcapistr          #+#    #+#             */
/*   Updated: 2024/07/16 14:48:13 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BLANKS
#  define BLANKS " \t\n"
# endif

typedef struct s_config
{
	int		parsing_map;
	int		parsing_done;
	char	*p_line;
	char	*p_trim;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	int		f_color[3];
	int		c_color[3];
	char	**map;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player_direction;
	int		player_count;
}			t_config;

// check
void		check_args(int argc, char **argv);
void		check_config(void);
void		check_texture(char *texture);
void		check_color(int color[3]);
void		check_map(char **map, int height);

// parse
void		parse_file(char *filename);
void		parse_line(char *line);

// utils
t_config	*get_config(void);
void		init_config(void);
void		free_config(void);

int			has_extension(char *filename, char *extension);

void		cub3d_exit(char *error);
int			cub3d_atoi(char *str, char **strs, int pos);

#endif
