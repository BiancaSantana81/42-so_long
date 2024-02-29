/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_put_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:32:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 14:25:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	draw_apples(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->apple->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	return (0);
}

int	draw_rock(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->rock->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	return (0);
}

int	draw_exit(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->exit->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	if (mlx_image_to_window(game->mlx,
			game->love->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	return (0);
}

int	draw_fire(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->fire->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	if (mlx_image_to_window(game->mlx,
			game->high_fire->img, y * BLOCK, x * BLOCK) < 0)
		ft_error(game);
	return (0);
}

int	draw_hudson(t_game *game)
{
	if (mlx_image_to_window(game->mlx,
			game->hudson_still->img,
			game->player_y * BLOCK, game->player_x * BLOCK) < 0)
		ft_error(game);
	if (mlx_image_to_window(game->mlx,
			game->hudson_move->img,
			game->player_y * BLOCK, game->player_x * BLOCK) < 0)
		ft_error(game);
	game->hudson_still->x = game->player_x;
	game->hudson_still->y = game->player_y;
	// game->hudson_move->x = game->player_x_m;
	// game->hudson_move->y = game->player_y_m;
	return (0);
}
