/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:26 by jcapistr          #+#    #+#             */
/*   Updated: 2024/07/15 14:47:26 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

void	check_texture(char *texture)
{
	int	fd;

	if (!texture)
		cub3d_exit("Missing texture");
	if (!has_extension(texture, "xpm"))
		cub3d_exit("Texture missing .xpm extension");
	if (ft_strchr(texture, ' ') || ft_strchr(texture, '\t'))
		cub3d_exit("Invalid texture syntax");
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		cub3d_exit("Texture does not exist or cannot be opened");
	close(fd);
}
