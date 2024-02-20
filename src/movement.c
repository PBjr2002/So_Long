/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:11 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/20 15:01:21 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_possible(t_list *pos, int x, int y, t_vars *vars)
{
	t_list	*temp;

	if (!pos)
		return (0);
	if (pos->next)
		temp = pos->next;
	else
		temp = pos;
	if (is_there_a_wall(vars, x, y) == -1)
		return (-1);
	while (temp->next)
	{
		if (temp->x == x && temp->y == y)
		{
			print_msg(-1);
			quit_game(vars, EXIT_FAILURE);
		}
		temp = temp->next;
	}
	return (0);
}

void	move_player(t_vars *vars, int move, char **map)
{
	int	x;
	int	y;

	x = get_head_x(map);
	y = get_head_y(map);
	if (vars->player_size == 1)
		vars->player_size++;
	if (move == UP)
		do_the_move(vars, move);
	else if (move == DOWN)
		do_the_move(vars, move);
	else if (move == RIGHT)
		do_the_move(vars, move);
	else if (move == LEFT)
		do_the_move(vars, move);
	check_move(vars, move, x, y);
}

void	change_map(t_vars *vars, int move)
{
	int	n;
	int	i;

	n = -1;
	while (vars->p_map[++n])
	{
		i = -1;
		while (vars->p_map[n][++i] && vars->p_map[n][i] != '\n')
		{
			if (vars->p_map[n][i] == 'P')
			{
				if (move == UP && vars->p_map[n - 1][i] != '1')
					change_map_up(vars, n, i);
				else if (move == DOWN && vars->p_map[n + 1][i] != '1')
					change_map_down(vars, n, i);
				else if (move == RIGHT && vars->p_map[n][i + 1] != '1')
					change_map_right(vars, n, i);
				else if (move == LEFT && vars->p_map[n][i - 1] != '1')
					change_map_left(vars, n, i);
				return ;
			}
		}
	}
}

void	remove_collectible(t_vars *vars, int x, int y)
{
	int	n;
	int	i;

	n = 0;
	while (vars->og_map[n])
	{
		i = 0;
		while (vars->og_map[n][i] && vars->og_map[n][i] != '\n')
		{
			if (i == x && n == y)
				vars->og_map[n][i] = '0';
			i++;
		}
		n++;
	}
}

void	remove_collectible_player_map(t_vars *vars, int x, int y)
{
	int	n;
	int	i;

	n = 0;
	while (vars->p_map[n])
	{
		i = 0;
		while (vars->p_map[n][i] && vars->p_map[n][i] != '\n')
		{
			if (i == x && n == y)
				remove_pos_coll(vars, n, i);
			i++;
		}
		n++;
	}
}
