/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:38:47 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/01 09:46:40 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	game->exit = load_images(game, "assets/sprites/exit.png");
	game->love = load_images(game, "assets/sprites/love.png");
	game->love->img->enabled = false;
	game->apple = load_images(game, "assets/sprites/apple.png");
	game->fire = load_images(game, "assets/sprites/fire.png");
	game->high_fire = load_images(game, "assets/sprites/high_fire.png");
	game->high_fire->img->enabled = false;
	game->hudson_still = load_images(game, "assets/sprites/hudson_still.png");
	game->hudson_still_l
		= load_images(game, "assets/sprites/hudson_still_l.png");
	game->hudson_still_l->img->enabled = false;
	game->hudson_move = load_images(game, "assets/sprites/hudson_move.png");
	game->hudson_move->img->enabled = false;
	game->hudson_move_l = load_images(game, "assets/sprites/hudson_move_l.png");
	game->hudson_move_l->img->enabled = false;
	game->counter = load_images(game, "assets/sprites/counter.png");
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
	draw_hudson(game);
	game->player_data = game->hudson_still;
	game->player_data_l = game->hudson_still_l;
	game->player_data_move = game->hudson_move;
	game->player_data_move_l = game->hudson_move_l;
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
