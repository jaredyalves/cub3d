#include "cub3d.h"

#include <stdio.h>

int	main(const int argc, char **argv)
{
	t_config	config;

	check_args(argc, argv);
	init_config(&config);
	parse_file(&config, argv[1]);
	printf("North Texture: %s\n", config.north_texture);
	printf("South Texture: %s\n", config.south_texture);
	printf("West Texture: %s\n", config.west_texture);
	printf("East Texture: %s\n", config.east_texture);
	printf("Floor Color: %d,%d,%d\n", config.floor_color[0], config.floor_color[1], config.floor_color[2]);
	printf("Ceiling Color: %d,%d,%d\n", config.ceiling_color[0], config.ceiling_color[1], config.ceiling_color[2]);
	printf("Map:\n");
	for (int i = 0; i < config.map_height; i++)
	{
		printf("%s\n", config.map[i]);
	}
}
