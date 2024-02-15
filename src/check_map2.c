/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:56:23 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/10 17:38:11 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_exit_and_colect(char **map)
{
	int	exit;
	int	collectibles;
	int	n;
	int	i;

	n = 0;
	exit = 0;
	collectibles = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (map[n][i] == 'E')
				exit++;
			else if (map[n][i] == 'C')
				collectibles++;
			i++;
		}
		n++;
	}
	if (exit != 1 || collectibles < 1)
		return (-1);
	return (0);
}

int	check_for_walls(char **map)
{
	int	n;
	int	i;

	n = 0;
	while (map[n])
	{
		i = 0;
		if (map[n][0] != '1')
			return (-1);
		while (map[n][i] != '\n' && map[n][i])
			i++;
		if (map[n][i - 1] != '1')
			return (-1);
		n++;
	}
	if (check_walls_in_bottom_and_top(map) == -1)
		return (-1);
	return (0);
}

int	check_walls_in_bottom_and_top(char **map)
{
	int	i;
	int	n;

	n = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (n == 0 && map[n][i] != '1')
				return (-1);
			i++;
		}
		n++;
	}
	i = 0;
	while (map[n - 1][i])
	{
		if (map[n - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_for_invalid_content(char **map)
{
	int	n;
	int	i;

	n = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (map[n][i] != '1' && map[n][i] != '0' && map[n][i] != 'C' 
				&& map[n][i] != 'P' && map[n][i] != 'E')
				return (-1);
			i++;
		}
		n++;
	}
	return (0);
}
