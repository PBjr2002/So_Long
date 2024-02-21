/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:27:41 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/21 14:31:38 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int mode)
{
	if (mode == 1)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	else if (mode == 2)
		ft_putstr_fd("Invalid map name\n", 2);
	else if (mode == 3)
		ft_putstr_fd("Invalid map\n", 2);
	exit(EXIT_FAILURE);
}

void	print_msg(int mode)
{
	if (mode == -1)
		ft_putstr_fd("\nOops seems like Game Over\n\n", 1);
	else if (mode == 1)
		ft_putstr_fd("\nCongrats u just beat snake 1.5!!!\n\n", 1);
	else if (mode == 2)
		ft_putstr_fd("\nDid you really gave up midway through ?\n\n", 1);
}

void	ft_clear_lst(t_list *pos)
{
	t_list	*next_node;

	if (!pos)
		return ;
	while (pos)
	{
		next_node = pos->next;
		free(pos);
		pos = next_node;
	}
	pos = NULL;
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
