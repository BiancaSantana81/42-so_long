/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:43:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/01 10:18:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	animations(void *param)
{
	t_game	*game;
	int32_t	time;

	game = (t_game *)param;
	time = (int)(mlx_get_time() * 10);
	animation_fire(game, time);
	animation_hudson(game, time);
}

void	animation_fire(t_game *game, int time)
{
	if (time % 5 == 1)
	{
		game->fire->img->enabled = false;
		game->high_fire->img->enabled = true;
	}
	if (time % 6 == 0)
	{
		game->fire->img->enabled = true;
		game->high_fire->img->enabled = false;
	}
}

void	animation_hudson(t_game *game, int time)
{
	if (time % 5 == 1)
	{
		if (game->side == '>')
		{
			hudson_right(game);
			game->player_data_move->img->enabled = true;
		}
		// if (game->side == '<')
		// 	hudson_left(game);
	}
		if (time % 6 == 1)
	{
		if (game->side == '>')
		{
			hudson_right(game);
			game->player_data_move->img->enabled = true;
		}
		// if (game->side == '<')
		// 	hudson_left(game);
	}
}

void	hudson_right(t_game *game)
{
	if (game->player_data->img->enabled == true)
	{
		game->player_data_l->img->enabled = false;
		game->player_data_move_l->img->enabled = false;
		game->player_data->img->enabled = false;
		// game->player_data_move->img->enabled = true;
	}
}

void	hudson_left(t_game *game)
{
	if (game->player_data_l->img->enabled == true)
	{
		game->player_data->img->enabled = false;
		game->player_data_move->img->enabled = false;
		game->player_data_l->img->enabled = false;
		game->player_data_move_l->img->enabled = true;
	}
}
