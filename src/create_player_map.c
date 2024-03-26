/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:30:32 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:42 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_player_map(t_vars *vars)
{
	char	**map;
	int		n;

	map = (char **)malloc(sizeof(char *)
			* ((get_map_height(vars->og_map) * 2) + 1));
	n = 0;
	while (n < (get_map_height(vars->og_map) * 2))
	{
		map[n] = ft_calloc(sizeof(char), (get_map_width(vars->og_map) * 2) + 1);
		n++;
	}
	fill_p_map(vars, map);
	map[n] = NULL;
	vars->p_map = map;
}

void	fill_p_map(t_vars *vars, char **map)
{
	int		x;
	int		y;

	y = -1;
	while (vars->og_map[++y])
	{
		x = -1;
		while (vars->og_map[y][++x] && vars->og_map[y][x] != '\n')
		{
			if (vars->og_map[y][x] == 'P')
			{
				map[(y * 2)][(x * 2)] = vars->og_map[y][x];
				map[(y * 2)][(x * 2) + 1] = '0';
				map[(y * 2) + 1][(x * 2)] = '0';
				map[(y * 2) + 1][(x * 2) + 1] = '0';
			}
			else
			{
				map[(y * 2)][(x * 2)] = vars->og_map[y][x];
				map[(y * 2)][(x * 2) + 1] = vars->og_map[y][x];
				map[(y * 2) + 1][(x * 2)] = vars->og_map[y][x];
				map[(y * 2) + 1][(x * 2) + 1] = vars->og_map[y][x];
			}
		}
	}
}

int	get_head_x(char **map)
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
				return (i);
			i++;
		}
		n++;
	}
	return (0);
}

int	get_head_y(char **map)
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
				return (n);
			i++;
		}
		n++;
	}
	return (0);
}
