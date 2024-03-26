/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:38 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:48 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	there_is_a_way(char **map)
{
	char	**map_dup;
	int		player_x;
	int		player_y;

	map_dup = duplicate_map(map);
	get_player_pos(map_dup, &player_x, &player_y);
	flood_fill(map_dup, player_x, player_y);
	if (check_for_path(map_dup) == -1)
	{
		free_map(map_dup);
		return (-1);
	}
	free_map(map_dup);
	return (0);
}

void	flood_fill(char	**map, int x, int y)
{
	int	width;
	int	height;

	width = get_map_width(map);
	height = get_map_height(map);
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'X')
		return ;
	map[y][x] = 'F';
	flood_fill(map, (x + 1), y);
	flood_fill(map, (x - 1), y);
	flood_fill(map, x, (y + 1));
	flood_fill(map, x, (y - 1));
}

int	check_for_path(char **map)
{
	int	n;
	int	i;

	n = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (map[n][i] == 'E' || map[n][i] == 'C')
				return (-1);
			i++;
		}
		n++;
	}
	return (0);
}

void	get_player_pos(char **map, int *player_x, int *player_y)
{
	int	n;
	int	i;

	n = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (map[n][i] == 'P')
			{
				*player_x = i;
				*player_y = n;
				return ;
			}
			i++;
		}
		n++;
	}
}

void	free_map(char **map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		free(map[n]);
		n++;
	}
	free(map);
}
