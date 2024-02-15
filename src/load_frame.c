/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:12 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 17:12:59 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_frame(t_vars vars, int move)
{
	char	*move_str;
	char	*new_mstr;

	load_imgs(&vars, move);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, quit_game, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, check_key, &vars);
	move_str = ft_itoa(vars.moves);
	new_mstr = ft_strjoin("moves : ", move_str);
	mlx_string_put(vars.mlx, vars.win, 16, 16, (int)0x0cf7ea, new_mstr);
	free(move_str);
	free(new_mstr);
	mlx_loop_hook(vars.mlx, repeat_key, &vars);
	mlx_loop(vars.mlx);
}

int	repeat_key(t_vars *vars)
{
	if (vars->last_KC == XK_a || vars->last_KC == XK_Left)
		move_player(vars, LEFT, vars->p_map);
	else if (vars->last_KC == XK_d || vars->last_KC == XK_Right)
		move_player(vars, RIGHT, vars->p_map);
	else if (vars->last_KC == XK_w || vars->last_KC == XK_Up)
		move_player(vars, UP, vars->p_map);
	else if (vars->last_KC == XK_s || vars->last_KC == XK_Down)
		move_player(vars, DOWN, vars->p_map);
	return (1);
}

int	check_key(int keycode, t_vars *vars)
{
	if ((vars->last_KC != XK_d && vars->last_KC != XK_Right) && (keycode == XK_a || keycode == XK_Left))
	{
		vars->last_KC = keycode;
		move_player(vars, LEFT, vars->p_map);
	}
	else if ((vars->last_KC != XK_a && vars->last_KC != XK_Left) && (keycode == XK_d || keycode == XK_Right))
	{
		vars->last_KC = keycode;
		move_player(vars, RIGHT, vars->p_map);
	}
	else if ((vars->last_KC != XK_s && vars->last_KC != XK_Down) && (keycode == XK_w || keycode == XK_Up))
	{
		vars->last_KC = keycode;
		move_player(vars, UP, vars->p_map);
	}
	else if ((vars->last_KC != XK_w && vars->last_KC != XK_Up) && (keycode == XK_s || keycode == XK_Down))
	{
		vars->last_KC = keycode;
		move_player(vars, DOWN, vars->p_map);
	}
	else if (keycode == XK_Escape)
		quit_game(vars, EXIT_SUCCESS);
	return (1);
}

int	quit_game(t_vars *vars, int signal)
{
	free(vars->timer);
	free_player(vars);
	ft_clear_lst(vars->pos);
	free_map(vars->p_map);
	free_map(vars->og_map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(signal);
	return (0);
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
