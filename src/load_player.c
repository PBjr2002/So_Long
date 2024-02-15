/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:30:41 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/15 16:34:14 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_head(t_player *p, t_vars *vars)
{
	p->head1 = new_file_img("./textures/Head_up_32.xpm",
			vars->mlx, vars->win);
	p->head2 = new_file_img("./textures/Head_down_32.xpm",
			vars->mlx, vars->win);
	p->head3 = new_file_img("./textures/Head_left_32.xpm",
			vars->mlx, vars->win);
	p->head4 = new_file_img("./textures/Head_right_32.xpm",
			vars->mlx, vars->win);
}

void	load_player_body(t_player *p, t_vars *vars)
{
	p->body1 = new_file_img("./textures/Body_horizontal_32.xpm",
			vars->mlx, vars->win);
	p->body2 = new_file_img("./textures/Body_vertical_32.xpm",
			vars->mlx, vars->win);
	p->body3 = new_file_img("./textures/Body_right_to_down_32.xpm",
			vars->mlx, vars->win);
	p->body4 = new_file_img("./textures/Body_right_to_up_32.xpm",
			vars->mlx, vars->win);
	p->body5 = new_file_img("./textures/Body_up_to_left_32.xpm",
			vars->mlx, vars->win);
	p->body6 = new_file_img("./textures/Body_up_to_right_32.xpm",
			vars->mlx, vars->win);
}

void	load_player_tail(t_player *p, t_vars *vars)
{
	p->tail1 = new_file_img("./textures/Tail_up_32.xpm",
			vars->mlx, vars->win);
	p->tail2 = new_file_img("./textures/Tail_down_32.xpm",
			vars->mlx, vars->win);
	p->tail3 = new_file_img("./textures/Tail_left_32.xpm",
			vars->mlx, vars->win);
	p->tail4 = new_file_img("./textures/Tail_right_32.xpm",
			vars->mlx, vars->win);
}

void	free_player(t_vars *vars)
{
	free_head(vars);
	free_body(vars);
	free_tail(vars);
	free(vars->player);
}
