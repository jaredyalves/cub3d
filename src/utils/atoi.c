/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:26 by jcapistr          #+#    #+#             */
/*   Updated: 2024/07/15 14:47:26 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

static void	free_strs(char **strs, int pos)
{
	int	i;

	if (strs)
	{
		i = pos;
		while (strs[i])
			free(strs[i++]);
		free(strs);
	}
}

int	cub3d_atoi(char *str, char **strs, int pos)
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
		{
			free_strs(strs, pos);
			cub3d_exit("Invalid number value");
		}
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}
