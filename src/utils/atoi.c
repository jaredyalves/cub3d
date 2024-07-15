#include "cub3d.h"

int	cub3d_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			cub3d_exit("Invalid number value");
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}
