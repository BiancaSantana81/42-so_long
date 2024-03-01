/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:12:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 17:28:37 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	player_movemnts(t_game *game, char pos, char op)
{
	int	result;

	result = 0;
	if (pos == 'x')
		result = player_movement_x(game, op);
	if (pos == 'y')
		result = player_movement_y(game, op);
	return (result);
}

int	player_movement_x(t_game *game, char op)
{
	if (op == '-' && game->map.map[game->player_x][game->player_y - 1] != '1')
	{
		game->player_y--;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
		return (0);
	}
	else if (op == '+'
		&& game->map.map[game->player_x][game->player_y + 1] != '1')
	{
		game->player_y++;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
		return (0);
	}
	return (1);
}

int	player_movement_y(t_game *game, char op)
{
	if (op == '-' && game->map.map[game->player_x - 1][game->player_y] != '1')
	{
		game->player_x--;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
		return (0);
	}
	else if (op == '+'
		&& game->map.map[game->player_x +1][game->player_y] != '1')
	{
		game->player_x++;
		game->n_moves++;
		ft_printf("moves: %d\n", game->n_moves);
		counter(game);
		return (0);
	}
	return (1);
}
