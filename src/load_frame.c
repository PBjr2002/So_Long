/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:12 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/15 19:46:20 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_frame(t_vars vars, int move)
{
	char	*move_str;
	char	*new_mstr;

	load_imgs(&vars, move);
	if (vars.player_size == 1)
		vars.player_size++;
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

int	check_key(int kc, t_vars *vars)
{
	if ((vars->last_kc != XK_w && vars->last_kc != XK_Up)
		&& (kc == XK_s || kc == XK_Down))
		check_up_or_down(vars, kc);
	else if ((vars->last_kc != XK_s && vars->last_kc != XK_Down)
		&& (kc == XK_w || kc == XK_Up))
		check_up_or_down(vars, kc);
	else if ((vars->last_kc != XK_a && vars->last_kc != XK_Left)
		&& (kc == XK_d || kc == XK_Right))
		check_left_or_right(vars, kc);
	else if ((vars->last_kc != XK_d && vars->last_kc != XK_Right)
		&& (kc == XK_a || kc == XK_Left))
		check_left_or_right(vars, kc);
	else if (kc == XK_Escape)
		quit_game(vars, EXIT_SUCCESS);
	return (1);
}

int	repeat_key(t_vars *vars)
{
	if (vars->last_kc == XK_a || vars->last_kc == XK_Left)
		move_player(vars, LEFT, vars->p_map);
	else if (vars->last_kc == XK_d || vars->last_kc == XK_Right)
		move_player(vars, RIGHT, vars->p_map);
	else if (vars->last_kc == XK_w || vars->last_kc == XK_Up)
		move_player(vars, UP, vars->p_map);
	else if (vars->last_kc == XK_s || vars->last_kc == XK_Down)
		move_player(vars, DOWN, vars->p_map);
	return (1);
}

void	check_up_or_down(t_vars *vars, int kc)
{
	if (kc == XK_w || kc == XK_Up)
	{
		vars->last_kc = kc;
		move_player(vars, UP, vars->p_map);
	}
	else if (kc == XK_s || kc == XK_Down)
	{
		vars->last_kc = kc;
		move_player(vars, DOWN, vars->p_map);
	}
}

void	check_left_or_right(t_vars *vars, int kc)
{
	if (kc == XK_a || kc == XK_Left)
	{
		vars->last_kc = kc;
		move_player(vars, LEFT, vars->p_map);
	}
	else if (kc == XK_d || kc == XK_Right)
	{
		vars->last_kc = kc;
		move_player(vars, RIGHT, vars->p_map);
	}
}
