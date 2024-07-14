#include "cub3d.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	init_config();
	parse_file(argv[1]);
	check_config();
	// --- DEBUG
	printf("--- Textures\n");
	printf("N Texture: %s\n", get_config()->n_texture);
	printf("S Texture: %s\n", get_config()->s_texture);
	printf("W Texture: %s\n", get_config()->w_texture);
	printf("E Texture: %s\n", get_config()->e_texture);
	printf("--- Floor Colors\n");
	printf("R: %d\n", get_config()->f_color[0]);
	printf("G: %d\n", get_config()->f_color[1]);
	printf("B: %d\n", get_config()->f_color[2]);
	printf("--- Ceiling Colors\n");
	printf("R: %d\n", get_config()->c_color[0]);
	printf("G: %d\n", get_config()->c_color[1]);
	printf("B: %d\n", get_config()->c_color[2]);
	printf("--- Map\n");
	for (int i = 0; i < get_config()->map_height; ++i)
	{
		printf("%s\n", get_config()->map[i]);
	}
	// --- DEBUG
	free_config();
}
