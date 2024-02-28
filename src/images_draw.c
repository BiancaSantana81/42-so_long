/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:38:47 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 16:10:00 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sprite	*load_images(t_game	*game, char *path)
{
	t_sprite	*sprites;

	sprites = ft_calloc(1, sizeof(t_sprite));
	if (!sprites)
		sprites = NULL;
	sprites->texture = mlx_load_png(path);
	if (!sprites->texture)
		ft_error(game);
	sprites->img = mlx_texture_to_image(game->mlx, sprites->texture);
	mlx_resize_image (sprites->img, SIZE * ZOOM, SIZE * ZOOM);
	return (sprites);
}

void	get_images(t_game *game)
{
	game->floor = load_images(game, "assets/sprites/floor.png");
	game->rock = load_images(game, "assets/sprites/rock.png");
	game->exit = load_images(game, "assets/sprites/love.png");
	game->apple = load_images(game, "assets/sprites/apple.png");
	game->fire = load_images(game, "assets/sprites/fire.png");
	game->high_fire = load_images(game, "assets/sprites/high_fire.png");
	game->high_fire->img->enabled = false;
	game->hudson_still = load_images(game, "assets/sprites/hudson_still.png");
	game->counter = load_images(game, "assets/sprites/counter.png");
	game->exit->img->enabled = false;
}

int	draw_images(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	while (game->map.map[line] != NULL)
	{
		column = 0;
		while (game->map.map[line][column])
		{
			aux_draw_images(game, line, column);
			column++;
		}
		line++;
	}
	build_counter(game);
	draw_hudson_still(game);
	game->player_data = game->hudson_still;
	return (0);
}

void	aux_draw_images(t_game *game, int line, int column)
{
	if (mlx_image_to_window(game->mlx,
			game->floor->img, column * BLOCK, line * BLOCK) < 0)
		ft_error(game);
	if (game->map.map[line][column] == 'C')
		draw_apples(game, line, column);
	if (game->map.map[line][column] == 'E')
		draw_exit(game, line, column);
	if (game->map.map[line][column] == '1')
		draw_rock(game, line, column);
	if (game->map.map[line][column] == 'F')
		draw_fire(game, line, column);
}
