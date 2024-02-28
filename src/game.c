/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:58:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 16:14:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_struct_map(t_map *map)
{
	*map = (t_map){0};
	map->fd = 0;
	map->bytes_read = 0;
	map->count_bytes = 0;
	map->lines = 0;
	map->columns = 0;
	map->n_collectible = 0;
	map->n_exit = 0;
	map->n_player = 0;
	map->invalid_character = 0;
	map->line_break = 1;
}

void	init_struct(t_game *game)
{
	*game = (t_game){0};
	game->mlx = NULL;
	game->flag = 0;
	game->line = 0;
	game->column = 0;
	game->count_fire = 0;
	game->count_collectible = 0;
	game->remove_collectible = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->n_moves = 0;
	game->player_data = NULL;
	game->floor = NULL;
	game->rock = NULL;
	game->exit = NULL;
	game->hudson_still = NULL;
	game->apple = NULL;
	game->high_fire = NULL;
	game->fire = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game);
	if (validations(argc, argv, &game))
		return (EXIT_FAILURE);
	init_game(&game);
	return (EXIT_SUCCESS);
}

int	init_game(t_game *game)
{
	int	map_column;
	int	map_line;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map_column = BLOCK * game->column;
	map_line = BLOCK * game->line;
	game->mlx = mlx_init(map_column, map_line, "Adventure Island", true);
	if (!game->mlx)
		puts(mlx_strerror(mlx_errno));
	get_images(game);
	draw_images(game);
	mlx_key_hook(game->mlx, &requested_movements, game);
	mlx_loop_hook(game->mlx, &animations, game);
	mlx_close_hook(game->mlx, free_and_close, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
