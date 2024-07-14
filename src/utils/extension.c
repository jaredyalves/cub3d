#include "libft.h"

int	has_extension(char *filename, char *extension)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	return (dot && !ft_strncmp(dot + 1, extension, ft_strlen(extension) + 1));
}
