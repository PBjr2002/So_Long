/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:17:08 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:30:02 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs(t_vars *vars, int move)
{
	load_bkgrnd(vars->og_map, vars->map, vars->bkgrnd);
	if (vars->player_size == 1)
		load_layer2(vars, DOWN);
	else
		load_layer2(vars, move);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bkgrnd->img, 0, 0);
}

void	load_bkgrnd(char **map, t_map *img, t_imgs *bkgrnd)
{
	int	i;
	int	n;
	int	width;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		n = 0;
		width = 0;
		while (map[i][n] && map[i][n] != '\n')
		{
			if (map[i][n] == '1')
				put_img_to_img(bkgrnd, img->wall, width, height);
			else
				put_img_to_img(bkgrnd, img->grnd, width, height);
			width = width + 64;
			n++;
		}
		height = height + 64;
		i++;
	}
}

t_map	*load_map_imgs(t_vars *vars)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->wall = new_file_img("./textures/Wall.xpm",
			vars->mlx, vars->win);
	map->grnd = new_file_img("./textures/Floor.xpm",
			vars->mlx, vars->win);
	map->coll = new_file_img("./textures/Collectible.xpm",
			vars->mlx, vars->win);
	map->exit = new_file_img("./textures/Exit.xpm",
			vars->mlx, vars->win);
	map->enemy = new_file_img("./textures/Round_cactus.xpm",
			vars->mlx, vars->win);
	return (map);
}

void	free_map_imgs(t_vars *mlx, t_map *map)
{
	mlx_destroy_image(mlx, map->wall->img);
	free(map->wall);
	mlx_destroy_image(mlx, map->grnd->img);
	free(map->grnd);
	mlx_destroy_image(mlx, map->coll->img);
	free(map->coll);
	mlx_destroy_image(mlx, map->exit->img);
	free(map->exit);
	mlx_destroy_image(mlx, map->enemy->img);
	free(map->enemy);
	free(map);
}

t_player	*load_player_imgs(t_vars *vars)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	load_player_head(player, vars);
	load_player_body(player, vars);
	load_player_tail(player, vars);
	return (player);
}
