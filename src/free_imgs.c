/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:49:48 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 17:00:34 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_head(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player->head1->img);
	free(vars->player->head1);
	mlx_destroy_image(vars->mlx, vars->player->head2->img);
	free(vars->player->head2);
	mlx_destroy_image(vars->mlx, vars->player->head3->img);
	free(vars->player->head3);
	mlx_destroy_image(vars->mlx, vars->player->head4->img);
	free(vars->player->head4);
}

void	free_body(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player->body1->img);
	free(vars->player->body1);
	mlx_destroy_image(vars->mlx, vars->player->body2->img);
	free(vars->player->body2);
	mlx_destroy_image(vars->mlx, vars->player->body3->img);
	free(vars->player->body3);
	mlx_destroy_image(vars->mlx, vars->player->body4->img);
	free(vars->player->body4);
	mlx_destroy_image(vars->mlx, vars->player->body5->img);
	free(vars->player->body5);
	mlx_destroy_image(vars->mlx, vars->player->body6->img);
	free(vars->player->body6);
}

void	free_tail(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player->tail1->img);
	free(vars->player->tail1);
	mlx_destroy_image(vars->mlx, vars->player->tail2->img);
	free(vars->player->tail2);
	mlx_destroy_image(vars->mlx, vars->player->tail3->img);
	free(vars->player->tail3);
	mlx_destroy_image(vars->mlx, vars->player->tail4->img);
	free(vars->player->tail4);
}
