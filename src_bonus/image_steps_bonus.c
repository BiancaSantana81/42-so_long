/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:11:15 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 14:07:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	build_counter(t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->counter->img, 0, 0) < 0)
		ft_error(game);
	game->steps = mlx_put_string(game->mlx, "Moves:", 20, 22);
	mlx_resize_image(game->counter->img, 2 * BLOCK, 1 * BLOCK);
	counter(game);
	return (0);
}

void	counter(t_game *game)
{
	char	*str;

	str = ft_itoa(game->n_moves);
	if (game->count_image)
		mlx_delete_image(game->mlx, game->count_image);
	game->count_image = mlx_put_string(game->mlx, str, 90, 22);
	free(str);
}
