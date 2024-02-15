/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:41 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/05 12:09:43 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\n' && map[0][width])
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	map_lines_counter(char *map)
{
	char	*str;
	int		n;
	int		fd;

	fd = open(map, O_RDONLY);
	n = 1;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		n++;
	}
	close(fd);
	return (n);
}

char	**create_map(char *file_name)
{
	char	**map;
	int		line_counter;
	int		n;
	int		fd;

	line_counter = map_lines_counter(file_name);
	n = 0;
	map = (char **)malloc(sizeof(char *) * (line_counter + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	while (n < line_counter)
	{
		map[n] = get_next_line(fd);
		n++;
	}
	map[n] = NULL;
	close(fd);
	return (map);
}

char	**duplicate_map(char **map)
{
	char	**duplicate;
	int		map_height;
	int		n;

	map_height = get_map_height(map);
	duplicate = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!duplicate)
		return (NULL);
	n = 0;
	while (n < map_height)
	{
		duplicate[n] = ft_strdup(map[n]);
		n++;
	}
	duplicate[n] = NULL;
	return (duplicate);
}
