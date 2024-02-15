/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:30:32 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 15:04:02 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_player_map(t_vars *vars)
{
	char	**map;
	int		x;
	int		y;
	int		n;
	int		i;
	
	map = (char **)malloc(sizeof(char *) * ((get_map_height(vars->og_map) * 2) + 1));
	n = 0;
	while (n < (get_map_height(vars->og_map) * 2))
	{
		map[n] = ft_calloc(sizeof(char), (get_map_width(vars->og_map) * 2) + 1);
		n++;
	}
	y = 0;
	n = 0;
	while (vars->og_map[y])
	{
		x = 0;
		i = 0;
		while (vars->og_map[y][x] && vars->og_map[y][x] != '\n')
		{
			if (vars->og_map[y][x] == 'P')
			{
				map[n][i] = vars->og_map[y][x];
				map[n][i + 1] = '0';
				map[n + 1][i] = '0';
				map[n + 1][i + 1] = '0';
			}
			else
			{
				map[n][i] = vars->og_map[y][x];
				map[n][i + 1] = vars->og_map[y][x];
				map[n + 1][i] = vars->og_map[y][x];
				map[n + 1][i + 1] = vars->og_map[y][x];
			}
			i = i + 2;
			x++;
		}
		n = n + 2;
		y++;
	}
	map[n] = NULL;
	vars->p_map = map;
}
