/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:47:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/01 11:59:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	side(t_game *game, char side)
{
	if (side == 'l')
	{
		game->hudson_still->img->enabled = false;
		game->hudson_still_l->img->enabled = true;
		game->player_data->img->instances[0].x -= BLOCK;
		game->player_data_l->img->instances[0].x -= BLOCK;
	}
	if (side == 'r')
	{
		game->hudson_still->img->enabled = true;
		game->hudson_still_l->img->enabled = false;
		game->player_data->img->instances[0].x += BLOCK;
		game->player_data_l->img->instances[0].x += BLOCK;
	}
}

void	move_player(t_game *game, char mov)
{
	if (mov == 's')
	{
		game->player_data->img->instances[0].y += BLOCK;
		game->player_data_l->img->instances[0].y += BLOCK;
	}
	else if (mov == 'w')
	{
		game->player_data->img->instances[0].y -= BLOCK;
		game->player_data_l->img->instances[0].y -= BLOCK;
	}
	else if (mov == 'a')
		side (game, 'l');
	else if (mov == 'd')
		side (game, 'r');
}
