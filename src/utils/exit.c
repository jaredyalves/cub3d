#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>

void	cub3d_exit(char *error)
{
	free_config();
	if (error)
	{
		ft_putstr_fd(error, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
