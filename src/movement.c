/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:11 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:53 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_possible(t_list *pos, int x, int y, t_vars *vars)
{
	t_list	*temp;
	int		n;
	int		i;

	if (!pos)
		return (0);
	if (pos->next)
		temp = pos->next;
	else
		temp = pos;
	while (temp->next)
	{
		if (temp->x == x && temp->y == y)
			quit_game(vars, EXIT_FAILURE);
		temp = temp->next;
	}
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

void	move_player(t_vars *vars, int move, char **map)
{
	int	x;
	int	y;

	x = get_head_x(map);
	y = get_head_y(map);
	if (vars->player_size == 1)
		vars->player_size++;
	if (move == UP)
	{
		if (is_move_possible(vars->pos, x, y - 1, vars) == 0)
		{
			gettimeofday((struct timeval *)vars->timer, NULL);
			if ((vars->timer->tv_sec * 1000000 + \
			vars->timer->tv_usec) > vars->frame)
			{
				change_map(vars, UP);
				vars->moves++;
				printf("moves : %d\n", vars->moves);
				ft_lstadd_front(&vars->pos, ft_lstnew(get_head_x(map), get_head_y(map)));
				if (ft_lstsize(vars->pos) > vars->player_size)
					ft_del_last(vars->pos);
				gettimeofday((struct timeval *)vars->timer, NULL);
				vars->frame = vars->timer->tv_sec * 1000000 \
				+ vars->timer->tv_usec + (1000000 / vars->speed);
			}
			if (x != get_head_x(map) || y != get_head_y(map))
			{
				vars->last_move = UP;
				free_player(vars);
				load_frame(*vars, UP);
			}
			else
			{
				free_player(vars);
				load_frame(*vars, vars->last_move);
			}
			
		}
	}
	else if (move == DOWN)
	{
		if (is_move_possible(vars->pos, x, y + 1, vars) == 0)
		{
			gettimeofday((struct timeval *)vars->timer, NULL);
			if ((vars->timer->tv_sec * 1000000 + \
			vars->timer->tv_usec) > vars->frame)
			{
				change_map(vars, DOWN);
				vars->moves++;
				printf("moves : %d\n", vars->moves);
				ft_lstadd_front(&vars->pos, ft_lstnew(get_head_x(map), get_head_y(map)));
				if (ft_lstsize(vars->pos) > vars->player_size)
					ft_del_last(vars->pos);
				gettimeofday((struct timeval *)vars->timer, NULL);
				vars->frame = vars->timer->tv_sec * 1000000 \
				+ vars->timer->tv_usec + (1000000 / vars->speed);
			}
			if (x != get_head_x(map) || y != get_head_y(map))
			{
				vars->last_move = DOWN;
				free_player(vars);
				load_frame(*vars, DOWN);
			}
			else
			{
				free_player(vars);
				load_frame(*vars, vars->last_move);
			}
		}
	}
	else if (move == RIGHT)
	{
		if (is_move_possible(vars->pos, x + 1, y, vars) == 0)
		{
			gettimeofday((struct timeval *)vars->timer, NULL);
			if ((vars->timer->tv_sec * 1000000 + \
			vars->timer->tv_usec) > vars->frame)
			{
				change_map(vars, RIGHT);
				vars->moves++;
				printf("moves : %d\n", vars->moves);
				ft_lstadd_front(&vars->pos, ft_lstnew(get_head_x(map), get_head_y(map)));
				if (ft_lstsize(vars->pos) > vars->player_size)
					ft_del_last(vars->pos);
				gettimeofday((struct timeval *)vars->timer, NULL);
				vars->frame = vars->timer->tv_sec * 1000000 \
				+ vars->timer->tv_usec + (1000000 / vars->speed);
			}
			if (x != get_head_x(map) || y != get_head_y(map))
			{
				vars->last_move = RIGHT;
				free_player(vars);
				load_frame(*vars, RIGHT);
			}
			else
			{
				free_player(vars);
				load_frame(*vars, vars->last_move);
			}
		}
	}
	else if (move == LEFT)
	{
		if (is_move_possible(vars->pos, x - 1, y, vars) == 0)
		{
			gettimeofday((struct timeval *)vars->timer, NULL);
			if ((vars->timer->tv_sec * 1000000 + \
			vars->timer->tv_usec) > vars->frame)
			{
				change_map(vars, LEFT);
				vars->moves++;
				printf("moves : %d\n", vars->moves);
				ft_lstadd_front(&vars->pos, ft_lstnew(get_head_x(map), get_head_y(map)));
				if (ft_lstsize(vars->pos) > vars->player_size)
					ft_del_last(vars->pos);
				gettimeofday((struct timeval *)vars->timer, NULL);
				vars->frame = vars->timer->tv_sec * 1000000 \
				+ vars->timer->tv_usec + (1000000 / vars->speed);
			}
			if (x != get_head_x(map) || y != get_head_y(map))
			{
				vars->last_move = LEFT;
				free_player(vars);
				load_frame(*vars, LEFT);
			}
			else
			{
				free_player(vars);
				load_frame(*vars, vars->last_move);
			}
		}
	}
}

void	change_map(t_vars *vars, int move)
{
	int	n;
	int	i;

	n = 0;
	while (vars->p_map[n])
	{
		i = 0;
		while (vars->p_map[n][i] && vars->p_map[n][i] != '\n')
		{
			if (vars->p_map[n][i] == 'P')
			{
				if (move == UP && (vars->p_map[n - 1][i] && vars->p_map[n - 1][i] != '1'))
				{
					if (vars->p_map[n - 1][i] == 'C')
					{
						remove_collectible(vars, i / 2, (n - 1) / 2);
						remove_collectible_player_map(vars, i, n - 1);
						vars->player_size++;
						vars->speed++;
					}
					else if (vars->og_map[(n - 1) / 2][i / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == 0)
					{
						vars->p_map[n - 1][i] = 'P';
						vars->p_map[n][i] = '0';
					}
					else if (vars->og_map[(n - 1) / 2][i / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == -1)
						quit_game(vars, EXIT_SUCCESS);
					if (vars->p_map[n - 1][i] != 'E')
					{
						vars->p_map[n - 1][i] = 'P';
						vars->p_map[n][i] = '0';	
					}
					return ;
				}
				else if (move == DOWN && (vars->p_map[n + 1][i] && vars->p_map[n + 1][i] != '1'))
				{
					if (vars->p_map[n + 1][i] == 'C')
					{
						remove_collectible(vars, i / 2, (n + 1) / 2);
						remove_collectible_player_map(vars, i, n + 1);
						vars->player_size++;
						vars->speed++;
					}
					else if (vars->og_map[(n + 1) / 2][i / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == 0)
					{
						vars->p_map[n + 1][i] = 'P';
						vars->p_map[n][i] = '0';
					}
					else if (vars->og_map[(n + 1) / 2][i / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == -1)
						quit_game(vars, EXIT_SUCCESS);
					if (vars->p_map[n + 1][i] != 'E')
					{
						vars->p_map[n + 1][i] = 'P';
						vars->p_map[n][i] = '0';	
					}
					return ;
				}
				else if (move == RIGHT && (vars->p_map[n][i + 1] && vars->p_map[n][i + 1] != '\n' && vars->p_map[n][i + 1] != '1'))
				{
					if (vars->p_map[n][i + 1] == 'C')
					{
						remove_collectible(vars, (i + 1) / 2, n / 2);
						remove_collectible_player_map(vars, i + 1, n);
						vars->player_size++;
						vars->speed++;
					}
					else if (vars->og_map[n / 2][(i + 1) / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == 0)
					{
						vars->p_map[n][i + 1] = 'P';
						vars->p_map[n][i] = '0';
					}
					else if (vars->og_map[n / 2][(i + 1) / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == -1)
						quit_game(vars, EXIT_SUCCESS);
					if (vars->p_map[n][i + 1] != 'E')
					{
						vars->p_map[n][i + 1] = 'P';
						vars->p_map[n][i] = '0';	
					}
					return ;
				}
				else if (move == LEFT && (vars->p_map[n][i - 1] && vars->p_map[n][i - 1] != '1'))
				{
					if (vars->p_map[n][i - 1] == 'C')
					{
						remove_collectible(vars, (i - 1) / 2, n / 2);
						remove_collectible_player_map(vars, i - 1, n);
						vars->player_size++;
						vars->speed++;
					}
					else if (vars->og_map[n / 2][(i - 1) / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == 0)
					{
						vars->p_map[n][i - 1] = 'P';
						vars->p_map[n][i] = '0';
					}
					else if (vars->og_map[n / 2][(i - 1) / 2] == 'E' && check_for_exit_and_colect(vars->og_map) == -1)
						quit_game(vars, EXIT_SUCCESS);
					if (vars->p_map[n][i - 1] != 'E')
					{
						vars->p_map[n][i - 1] = 'P';
						vars->p_map[n][i] = '0';	
					}
					return ;
				}
			}
			i++;
		}
		n++;
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
			i++;
		}
		n++;
	}
}
