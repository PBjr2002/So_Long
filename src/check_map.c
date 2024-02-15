/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:46:28 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/18 11:08:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_retangular(char **map)
{
	int	n;
	int	new_line;
	int	prev_line;

	n = 0;
	new_line = 0;
	prev_line = 0;
	while (map[n])
	{
		new_line = 0;
		while (map[n][new_line] != '\n' && map[n][new_line])
			new_line++;
		if (n == 0)
			prev_line = new_line;
		else
		{
			if (new_line != prev_line)
				return (-1);
			prev_line = new_line;
		}
		n++;
	}
	return (0);
}

int	check_for_stuff(char **map)
{
	int	n;
	int	i;
	int	player;
	int	free_space;

	n = 0;
	player = 0;
	free_space = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i])
		{
			if (map[n][i] == 'P')
				player++;
			else if (map[n][i] == '0')
				free_space++;
			i++;
		}
		n++;
	}
	if (player != 1 || check_for_exit_and_colect(map) == -1 || free_space < 1)
		return (-1);
	return (0);
}

int	validate_map(char **map)
{
	if (is_retangular(map) == -1 || check_for_stuff(map) == -1 
		|| check_for_walls(map) == -1 || check_for_invalid_content(map) == -1 
		|| there_is_a_way(map) == -1)
	{
		free_map(map);
		return (-1);
	}
	return (0);
}
