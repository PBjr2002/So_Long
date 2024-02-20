/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:10 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/20 15:01:06 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_map_up(t_vars *vars, int n, int i)
{
	if (vars->p_map[n - 1][i] == 'C')
	{
		remove_collectible(vars, i / 2, (n - 1) / 2);
		remove_collectible_player_map(vars, i, n - 1);
		vars->player_size++;
	}
	else if (vars->og_map[(n - 1) / 2][i / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == 0)
	{
		vars->p_map[n - 1][i] = 'P';
		vars->p_map[n][i] = '0';
	}
	else if (vars->og_map[(n - 1) / 2][i / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == -1)
	{
		print_msg(1);
		quit_game(vars, EXIT_SUCCESS);
	}
	if (vars->p_map[n - 1][i] != 'E')
	{
		vars->p_map[n - 1][i] = 'P';
		vars->p_map[n][i] = '0';
	}
}

void	change_map_down(t_vars *vars, int n, int i)
{
	if (vars->p_map[n + 1][i] == 'C')
	{
		remove_collectible(vars, i / 2, (n + 1) / 2);
		remove_collectible_player_map(vars, i, n + 1);
		vars->player_size++;
	}
	else if (vars->og_map[(n + 1) / 2][i / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == 0)
	{
		vars->p_map[n + 1][i] = 'P';
		vars->p_map[n][i] = '0';
	}
	else if (vars->og_map[(n + 1) / 2][i / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == -1)
	{
		print_msg(1);
		quit_game(vars, EXIT_SUCCESS);
	}
	if (vars->p_map[n + 1][i] != 'E')
	{
		vars->p_map[n + 1][i] = 'P';
		vars->p_map[n][i] = '0';
	}
}

void	change_map_right(t_vars *vars, int n, int i)
{
	if (vars->p_map[n][i + 1] == 'C')
	{
		remove_collectible(vars, (i + 1) / 2, n / 2);
		remove_collectible_player_map(vars, i + 1, n);
		vars->player_size++;
	}
	else if (vars->og_map[n / 2][(i + 1) / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == 0)
	{
		vars->p_map[n][i + 1] = 'P';
		vars->p_map[n][i] = '0';
	}
	else if (vars->og_map[n / 2][(i + 1) / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == -1)
	{
		print_msg(1);
		quit_game(vars, EXIT_SUCCESS);
	}
	if (vars->p_map[n][i + 1] != 'E')
	{
		vars->p_map[n][i + 1] = 'P';
		vars->p_map[n][i] = '0';
	}
}

void	change_map_left(t_vars *vars, int n, int i)
{
	if (vars->p_map[n][i - 1] == 'C')
	{
		remove_collectible(vars, (i - 1) / 2, n / 2);
		remove_collectible_player_map(vars, i - 1, n);
		vars->player_size++;
	}
	else if (vars->og_map[n / 2][(i - 1) / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == 0)
	{
		vars->p_map[n][i - 1] = 'P';
		vars->p_map[n][i] = '0';
	}
	else if (vars->og_map[n / 2][(i - 1) / 2] == 'E'
		&& check_for_exit_and_colect(vars->og_map) == -1)
	{
		print_msg(1);
		quit_game(vars, EXIT_SUCCESS);
	}
	if (vars->p_map[n][i - 1] != 'E')
	{
		vars->p_map[n][i - 1] = 'P';
		vars->p_map[n][i] = '0';
	}
}

void	remove_pos_coll(t_vars *vars, int n, int i)
{
	vars->p_map[n][i] = '0';
	if (vars->p_map[n - 1][i + 1] == 'C')
		vars->p_map[n - 1][i + 1] = '0';
	if (vars->p_map[n][i + 1] == 'C')
		vars->p_map[n][i + 1] = '0';
	if (vars->p_map[n + 1][i + 1] == 'C')
		vars->p_map[n + 1][i + 1] = '0';
	if (vars->p_map[n + 1][i] == 'C')
		vars->p_map[n + 1][i] = '0';
	if (vars->p_map[n + 1][i - 1] == 'C')
		vars->p_map[n + 1][i - 1] = '0';
	if (vars->p_map[n][i - 1] == 'C')
		vars->p_map[n][i - 1] = '0';
	if (vars->p_map[n - 1][i - 1] == 'C')
		vars->p_map[n - 1][i - 1] = '0';
	if (vars->p_map[n - 1][i] == 'C')
		vars->p_map[n - 1][i] = '0';
}
