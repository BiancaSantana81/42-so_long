/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:37:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 15:20:01 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	else if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		player_movement_y(game, 'y', '-' );
	else if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		player_movement_y(game, 'y', '+');
	else if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		player_movement_x(game, 'x', '-');
	else if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		player_movement_x(game, 'x', '+');
	updated_collectibles(game);
	if (game_over(game))
		return ;
	end_of_game(game);
}

void	player_movement_x(t_game *game, char pos, char op)
{
	int	new_x;

	new_x = game->player_data->img->instances[0].x;
	if (pos == 'x' && op == '-'
		&& game->map.map[game->player_x][game->player_y - 1] != '1')
	{
		new_x -= BLOCK;
		game->player_y--;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
	}
	else if (pos == 'x' && op == '+'
		&& game->map.map[game->player_x][game->player_y + 1] != '1')
	{
		new_x += BLOCK;
		game->player_y++;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
	}
	game->player_data->img->instances[0].x = new_x;
}

void	player_movement_y(t_game *game, char pos, char op)
{
	int	new_y;

	new_y = game->player_data->img->instances[0].y;
	if (pos == 'y' && op == '-'
		&& game->map.map[game->player_x - 1][game->player_y] != '1')
	{
		new_y -= BLOCK;
		game->player_x--;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
	}
	else if (pos == 'y' && op == '+'
		&& game->map.map[game->player_x +1][game->player_y] != '1')
	{
		new_y += BLOCK;
		game->player_x++;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
	}
	game->player_data->img->instances[0].y = new_y;
}
