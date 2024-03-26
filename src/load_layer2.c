/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_layer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:45:03 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:59 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_layer2(t_vars *vars, int move)
{
	int	i;
	int	n;

	i = 0;
	while (vars->og_map[i])
	{
		n = 0;
		while (vars->og_map[i][n])
		{
			if (vars->og_map[i][n] == 'E'
				&& check_for_exit_and_colect(vars->og_map) == -1)
				put_img_to_img(vars->bkgrnd, vars->map->exit, n * 64, i * 64);
			else if (vars->og_map[i][n] == 'E')
				put_img_to_img(vars->bkgrnd, vars->map->grnd, n * 64, i * 64);
			else if (vars->og_map[i][n] == 'C')
				put_img_to_img(vars->bkgrnd, vars->map->coll, n * 64, i * 64);
			else if (vars->og_map[i][n] == 'X')
				put_img_to_img(vars->bkgrnd, vars->map->enemy, n * 64, i * 64);
			n++;
		}
		i++;
	}
	player_put(vars, move);
}

void	player_put(t_vars *vars, int move)
{
	int	i;
	int	n;

	i = 0;
	while (vars->p_map[i])
	{
		n = 0;
		while (vars->p_map[i][n])
		{
			if (vars->p_map[i][n] == 'P')
				load_player_imgs_aftermove(vars, n * 32, i * 32, move);
			n++;
		}
		i++;
	}
}

void	load_player_imgs_aftermove(t_vars *vars, int wh, int ht, int move)
{
	if (move == DOWN && vars->player_size == 1)
		put_img_to_img(vars->bkgrnd, vars->player->head2, wh, ht);
	else if (move == UP || move == DOWN)
		put_player_up_or_down(vars, wh, ht, move);
	else if (move == LEFT || move == RIGHT)
		put_player_left_or_right(vars, wh, ht, move);
}

void	put_player_left_or_right(t_vars *vars, int wh, int ht, int move)
{
	if (move == RIGHT)
	{
		put_img_to_img(vars->bkgrnd, vars->player->head4, wh, ht);
		if (vars->player_size > 2)
			print_body(vars, wh, ht);
		else
			put_img_to_img(vars->bkgrnd, vars->player->tail4, wh - 32, ht);
	}
	else if (move == LEFT)
	{
		put_img_to_img(vars->bkgrnd, vars->player->head3, wh, ht);
		if (vars->player_size > 2)
			print_body(vars, wh, ht);
		else
			put_img_to_img(vars->bkgrnd, vars->player->tail3, wh + 32, ht);
	}
}

void	put_player_up_or_down(t_vars *vars, int wh, int ht, int move)
{
	if (move == DOWN)
	{
		put_img_to_img(vars->bkgrnd, vars->player->head2, wh, ht);
		if (vars->player_size > 2)
			print_body(vars, wh, ht);
		else
			put_img_to_img(vars->bkgrnd, vars->player->tail2, wh, ht - 32);
	}
	else if (move == UP)
	{
		put_img_to_img(vars->bkgrnd, vars->player->head1, wh, ht);
		if (vars->player_size > 2)
			print_body(vars, wh, ht);
		else
			put_img_to_img(vars->bkgrnd, vars->player->tail1, wh, ht + 32);
	}
}
