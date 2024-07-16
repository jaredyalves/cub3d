#include "cub3d.h"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	init_config();
	parse_file(argv[1]);
	check_config();
	free_config();
}
