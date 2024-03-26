/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:12 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:55 by pauberna         ###   ########.fr       */
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
	new_mstr = ft_strjoin("Moves Counter : ", move_str);
	mlx_string_put(vars.mlx, vars.win, 10, 32, (int)0xffffff, new_mstr);
	free(move_str);
	free(new_mstr);
	mlx_loop_hook(vars.mlx, repeat_key, &vars);
	mlx_loop(vars.mlx);
}

int	check_key(int kc, t_vars *vars)
{
	if (kc == XK_w && vars->last_move != DOWN)
		check_up_or_down(vars, kc);
	else if (kc == XK_a && vars->last_move != RIGHT)
		check_left_or_right(vars, kc);
	else if (kc == XK_s && vars->last_move != UP)
		check_up_or_down(vars, kc);
	else if (kc == XK_d && vars->last_move != LEFT)
		check_left_or_right(vars, kc);
	else if (kc == XK_Escape)
	{
		print_msg(2);
		quit_game(vars, EXIT_SUCCESS);
	}
	return (1);
}

int	repeat_key(t_vars *vars)
{
	if (vars->last_kc == XK_w)
		move_player(vars, UP, vars->p_map);
	else if (vars->last_kc == XK_a)
		move_player(vars, LEFT, vars->p_map);
	else if (vars->last_kc == XK_s)
		move_player(vars, DOWN, vars->p_map);
	else if (vars->last_kc == XK_d)
		move_player(vars, RIGHT, vars->p_map);
	return (1);
}

void	check_up_or_down(t_vars *vars, int kc)
{
	if (kc == XK_w)
	{
		if (is_there_a_wall_or_enemy(vars, get_head_x(vars->p_map),
				get_head_y(vars->p_map) - 1) == 0)
		{
			vars->last_kc = kc;
			move_player(vars, UP, vars->p_map);
		}
		else
			repeat_key(vars);
	}
	else if (kc == XK_s)
	{
		if (is_there_a_wall_or_enemy(vars, get_head_x(vars->p_map),
				get_head_y(vars->p_map) + 1) == 0)
		{
			vars->last_kc = kc;
			move_player(vars, DOWN, vars->p_map);
		}
		else
			repeat_key(vars);
	}
}

void	check_left_or_right(t_vars *vars, int kc)
{
	if (kc == XK_a)
	{
		if (is_there_a_wall_or_enemy(vars, get_head_x(vars->p_map) - 1,
				get_head_y(vars->p_map)) == 0)
		{
			vars->last_kc = kc;
			move_player(vars, LEFT, vars->p_map);
		}
		else
			repeat_key(vars);
	}
	else if (kc == XK_d)
	{
		if (is_there_a_wall_or_enemy(vars, get_head_x(vars->p_map) + 1,
				get_head_y(vars->p_map)) == 0)
		{
			vars->last_kc = kc;
			move_player(vars, RIGHT, vars->p_map);
		}
		else
			repeat_key(vars);
	}
}
