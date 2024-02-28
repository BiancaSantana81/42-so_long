/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:43:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 18:12:14 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	animations(void *param)
{
	t_game	*game;
	int32_t	time;

	game = (t_game *)param;
	time = (int)(mlx_get_time() * 10);
	animation_fire(game, time);
	// animation_hudson(game, time);
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

// void	animation_hudson(t_game *game, int time)
// {
// 	if (time % 5 == 0)
// 	{
// 		game->hudson_still->img->enabled = false;
// 		game->hudson_move->img->enabled = true;
// 	}
// 	if (time % 6 == 0)
// 	{
// 		game->hudson_still->img->enabled = true;
// 		game->hudson_move->img->enabled = false;
// 	}
// }
