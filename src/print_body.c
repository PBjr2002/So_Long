/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:19:19 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:30:31 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_body(t_vars *vars, int wh, int ht)
{
	t_list	*tmp;

	if (!vars->pos)
		return ;
	else
		tmp = vars->pos->next;
	while (tmp->next)
	{
		print_v_or_h(vars, tmp, &wh, &ht);
		print_dr_or_lu(vars, tmp, &wh, &ht);
		print_ld_or_ur(vars, tmp, &wh, &ht);
		tmp = tmp->next;
	}
	if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1)
		put_img_to_img(vars->bkgrnd, vars->player->tail1, wh, ht + 32);
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1)
		put_img_to_img(vars->bkgrnd, vars->player->tail2, wh, ht - 32);
	else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0)
		put_img_to_img(vars->bkgrnd, vars->player->tail3, wh + 32, ht);
	else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0)
		put_img_to_img(vars->bkgrnd, vars->player->tail4, wh - 32, ht);
}

void	print_v_or_h(t_vars *vars, t_list *tmp, int *wh, int *ht)
{
	if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body2, *wh, *ht + 32);
		*ht = *ht + 32;
	}
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body2, *wh, *ht - 32);
		*ht = *ht - 32;
	}
	else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body1, *wh - 32, *ht);
		*wh = *wh - 32;
	}
	else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body1, *wh + 32, *ht);
		*wh = *wh + 32;
	}
}

void	print_dr_or_lu(t_vars *vars, t_list *tmp, int *wh, int *ht)
{
	if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body3, *wh - 32, *ht);
		*wh = *wh - 32;
	}
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1
		&& tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body3, *wh, *ht - 32);
		*ht = *ht - 32;
	}
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1
		&& tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body4, *wh, *ht + 32);
		*ht = *ht + 32;
	}
	else if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body4, *wh + 32, *ht);
		*wh = *wh + 32;
	}
}

void	print_ld_or_ur(t_vars *vars, t_list *tmp, int *wh, int *ht)
{
	if (tmp->prev->x - tmp->x == -1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == -1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body5, *wh + 32, *ht);
		*wh = *wh + 32;
	}
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == 1
		&& tmp->x - tmp->next->x == 1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body5, *wh, *ht - 32);
		*ht = *ht - 32;
	}
	else if (tmp->prev->x - tmp->x == 1 && tmp->prev->y - tmp->y == 0
		&& tmp->x - tmp->next->x == 0 && tmp->y - tmp->next->y == 1)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body6, *wh - 32, *ht);
		*wh = *wh - 32;
	}
	else if (tmp->prev->x - tmp->x == 0 && tmp->prev->y - tmp->y == -1
		&& tmp->x - tmp->next->x == -1 && tmp->y - tmp->next->y == 0)
	{
		put_img_to_img(vars->bkgrnd, vars->player->body6, *wh, *ht + 32);
		*ht = *ht + 32;
	}
}
