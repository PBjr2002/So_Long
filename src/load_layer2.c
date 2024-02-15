/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_layer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:45:03 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 14:53:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_layer2(t_vars *vars, int move)
{
	int	i;
	int	n;
	int	width;
	int	height;

	i = 0;
	height = 0;
	while (vars->og_map[i])
	{
		n = 0;
		width = 0;
		while (vars->og_map[i][n])
		{
			if (vars->og_map[i][n] == 'E' && check_for_exit_and_colect(vars->og_map) == -1)
				put_img_to_img(vars->background, vars->map->exit, width, height);
			else if (vars->og_map[i][n] == 'E' && check_for_exit_and_colect(vars->og_map) == 0)
				put_img_to_img(vars->background, vars->map->grnd, width, height);
			else if (vars->og_map[i][n] == 'C')
				put_img_to_img(vars->background, vars->map->coll, width, height);
			width = width + 64;
			n++;
		}
		height = height + 64;
		i++;
	}
	i = 0;
	height = 0;
	while (vars->p_map[i])
	{
		n = 0;
		width = 0;
		while (vars->p_map[i][n])
		{
			if (vars->p_map[i][n] == 'P')
				load_player_imgs_aftermove(vars, width, height, move);
			width = width + 32;
			n++;
		}
		height = height + 32;
		i++;
	}
}

void	load_player_imgs_aftermove(t_vars *vars, int width, int height, int move)
{
	int	size;

	size = vars->player_size;
	if (move == DOWN && vars->player_size == 1)
		put_img_to_img(vars->background, vars->player->head2, width, height);
	else if (move == DOWN)
	{
		put_img_to_img(vars->background, vars->player->head2, width, height);
		if (size > 2)
			print_body(vars, width, height);
		else
			put_img_to_img(vars->background, vars->player->tail2, width, height - 32);
	}
	else if (move == UP)
	{
		put_img_to_img(vars->background, vars->player->head1, width, height);
		if (size > 2)
			print_body(vars, width, height);
		else
			put_img_to_img(vars->background, vars->player->tail1, width, height + 32);
	}
	else if (move == RIGHT)
	{
		put_img_to_img(vars->background, vars->player->head4, width, height);
		if (size > 2)
			print_body(vars, width, height);
		else
			put_img_to_img(vars->background, vars->player->tail4, width - 32, height);
	}
	else if (move == LEFT)
	{
		put_img_to_img(vars->background, vars->player->head3, width, height);
		if (size > 2)
			print_body(vars, width, height);
		else
			put_img_to_img(vars->background, vars->player->tail3, width + 32, height);
	}
}

void	print_body(t_vars *vars, int width, int height)
{
	t_list *tmp;

	if (!vars->pos)
		return ;
	else
		tmp = vars->pos->next;
	while (tmp->next)
	{
		//vertical
		if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
		{
			put_img_to_img(vars->background, vars->player->body2, width, height + 32);
			height = height + 32;
		}
		else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
		{
			put_img_to_img(vars->background, vars->player->body2, width, height - 32);
			height = height - 32;
		}
		//horizontal
		else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body1, width - 32, height);
			width = width - 32;
		}
		else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body1, width + 32, height);
			width = width + 32;
		}
		//right to down
		else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
		{
			put_img_to_img(vars->background, vars->player->body3, width - 32, height);
			width = width - 32;
		}
		else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1 && tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body3, width, height - 32);
			height = height - 32;
		}
		//left to up
		else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1 && tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body4, width, height + 32);
			height = height + 32;
		}
		else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
		{
			put_img_to_img(vars->background, vars->player->body4, width + 32, height);
			width = width + 32;
		}
		//up to left
		else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
		{
			put_img_to_img(vars->background, vars->player->body5, width + 32, height);
			width = width + 32;
		}
		else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1 && tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body5, width, height - 32);
			height = height - 32;
		}
		//up to right
		else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0 && tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
		{
			put_img_to_img(vars->background, vars->player->body6, width - 32, height);
			width = width - 32;
		}
		else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1 && tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
		{
			put_img_to_img(vars->background, vars->player->body6, width, height + 32);
			height = height + 32;
		}
		tmp = tmp->next;
	}
	if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1)
		put_img_to_img(vars->background, vars->player->tail1, width, height + 32);
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1)
		put_img_to_img(vars->background, vars->player->tail2, width, height - 32);
	else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0)
		put_img_to_img(vars->background, vars->player->tail3, width + 32, height);
	else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0)
		put_img_to_img(vars->background, vars->player->tail4, width - 32, height);
}
