/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:12:53 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 14:54:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name == NULL)
		return (-1);
	if (len < 5)
		return (-1);
	if (ft_strcmp(map_name + len - 4, ".ber") != 0)
		return (-1);
	return (0);
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		print_error(1);
	if (check_file_name(av[1]) == -1)
		print_error(2);
	vars.og_map = create_map(av[1]);
	if (validate_map(vars.og_map) == -1)
		print_error(3);
	create_player_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, get_map_width(vars.og_map) * 64, get_map_height(vars.og_map) * 64, "so_long");
	vars.player_size = 1;
	vars.pos = NULL;
	vars.last_KC = 0;
	vars.moves = 0;
	vars.frame = 1;
	vars.last_move = 2;
	vars.speed = 4;
	vars.timer = malloc(sizeof(t_timeval));
	load_frame(vars, 2);
	return (0);
}
