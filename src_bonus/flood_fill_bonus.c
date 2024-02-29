/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 11:25:53 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	aux_flood_fill(t_game *game, t_map *map, int x, int y)
{
	if ((x < 0 || x >= map->lines)
		|| (y < 0 || y >= map->columns)
		|| (game->map.clone[x][y] == '1'))
		return ;
	game->map.clone[x][y] = '1';
	aux_flood_fill(game, map, x - 1, y);
	aux_flood_fill(game, map, x + 1, y);
	aux_flood_fill(game, map, x, y - 1);
	aux_flood_fill(game, map, x, y + 1);
}

void	flood_fill(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.clone[x] != NULL)
	{
		y = 0;
		while (game->map.clone[x][y])
		{
			if (game->map.clone[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				aux_flood_fill(game, map, x, y);
				if (check_clone(game))
					game->flag++;
				break ;
			}
			y++;
		}
		x++;
	}
	free_map(game->map.clone);
}

int	check_clone(t_game *game)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (game->map.clone[x] != NULL)
	{
		y = 0;
		while (game->map.clone[x][y])
		{
			if (game->map.clone[x][y] == 'C' || game->map.clone[x][y] == 'E')
				count++;
			y++;
		}
		x++;
	}
	if (count != 0)
		return (1);
	return (0);
}
