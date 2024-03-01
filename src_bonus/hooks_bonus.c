/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:37:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 18:03:02 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1
			|| keydata.key == key2) && keydata.action == MLX_PRESS);
}

void	requested_movements(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		free_and_close(game);
		return ;
	}
	if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		if (player_movemnts(game, 'y', '-' ) == 0)
			move_player(game, 'w');
	if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		if (player_movemnts(game, 'y', '+') == 0)
			move_player(game, 's');
	if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		if (player_movemnts(game, 'x', '-') == 0)
			move_player(game, 'a');
	if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		if (player_movemnts(game, 'x', '+') == 0)
			move_player(game, 'd');
	updated_collectibles(game);
	if (game_over(game))
		return ;
	end_of_game(game);
}
