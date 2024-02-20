/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:27:47 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/20 11:57:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_there_a_wall(t_vars *vars, int x, int y)
{
	int		n;
	int		i;

	i = 0;
	while (vars->p_map[i])
	{
		n = 0;
		while (vars->p_map[i][n] && vars->p_map[i][n] != '\n')
		{
			if (vars->p_map[i][n] == '1' && i == y && n == x)
				return (-1);
			n++;
		}
		i++;
	}
	return (0);
}

void	do_the_move(t_vars *vars, int move)
{
	gettimeofday((struct timeval *)vars->timer, NULL);
	if ((vars->timer->tv_sec * 1000000 + \
	vars->timer->tv_usec) > vars->frame)
	{
		if (decide_move(vars, move) == 0)
		{
			vars->moves++;
			change_map(vars, move);
			ft_lstadd_front(&vars->pos, ft_lstnew(get_head_x(vars->p_map),
					get_head_y(vars->p_map)));
			if (ft_lstsize(vars->pos) > vars->player_size)
				ft_del_last(vars->pos);
		}
		gettimeofday((struct timeval *)vars->timer, NULL);
		vars->frame = vars->timer->tv_sec * 1000000 \
		+ vars->timer->tv_usec + (1000000 / vars->speed);
	}
}

void	check_move(t_vars *vars, int move, int x, int y)
{
	if (x != get_head_x(vars->p_map) || y != get_head_y(vars->p_map))
	{
		vars->last_move = move;
		free_player(vars);
		load_frame(*vars, move);
	}
	else
	{
		free_player(vars);
		load_frame(*vars, vars->last_move);
	}
}

int	decide_move(t_vars *vars, int move)
{
	if (move == UP)
	{
		if (is_move_possible(vars->pos, get_head_x(vars->p_map),
				get_head_y(vars->p_map) - 1, vars) == 0)
			return (0);
	}
	else if (move == DOWN)
	{
		if (is_move_possible(vars->pos, get_head_x(vars->p_map),
				get_head_y(vars->p_map) + 1, vars) == 0)
			return (0);
	}
	else if (move == LEFT)
	{
		if (is_move_possible(vars->pos, get_head_x(vars->p_map) - 1,
				get_head_y(vars->p_map), vars) == 0)
			return (0);
	}
	else if (move == RIGHT)
	{
		if (is_move_possible(vars->pos, get_head_x(vars->p_map) + 1,
				get_head_y(vars->p_map), vars) == 0)
			return (0);
	}
	return (-1);
}
