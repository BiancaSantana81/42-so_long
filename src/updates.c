/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:32:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 14:23:54 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	updated_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_collectible)
	{
		if (game->player_data->img->instances->x
			== game->apple->img->instances[i].x
			&& game->player_data->img->instances->y
			== game->apple->img->instances[i].y)
		{
			if (game->apple->img->instances[i].enabled)
			{
				game->apple->img->instances[i].enabled = false;
				game->remove_collectible--;
			}
		}
		i++;
	}
}

void	end_of_game(t_game *game)
{
	if (game->remove_collectible == 0)
	{
		game->exit->img->enabled = true;
		if (game->player_data->img->instances->x
			== game->exit->img->instances->x
			&& game->player_data->img->instances->y
			== game->exit->img->instances->y)
		{
			free_and_close(game);
			ft_printf("YOU WIN!!\n");
		}
	}
}

int	game_over(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_fire)
	{
		if (game->player_data->img->instances->x
			== game->fire->img->instances[i].x
			&& game->player_data->img->instances->y
			== game->fire->img->instances[i].y)
		{
			free_and_close(game);
			ft_printf("YOU LOSER!!\n");
			return (1);
		}
	i++;
	}
	return (0);
}

void	free_and_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_map(game->map.map);
	free_sprites(game, game->player_data);
	free_sprites(game, game->floor);
	free_sprites(game, game->rock);
	free_sprites(game, game->exit);
	free_sprites(game, game->apple);
	free_sprites(game, game->fire);
	free_sprites(game, game->counter);
	mlx_close_window(game->mlx);
}

void	free_sprites(t_game *game, t_sprite *sprites)
{
	if (sprites->img)
		mlx_delete_image(game->mlx, sprites->img);
	if (sprites->texture)
		mlx_delete_texture(sprites->texture);
	free(sprites);
}
