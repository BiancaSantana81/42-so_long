/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:26:15 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 14:08:17 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	check_params(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (0);
	}
	if (ft_strrncmp(argv[1], ".ber", 4))
	{
		ft_putstr_fd(ERROR_EXTENSION, 2);
		return (0);
	}
	return (1);
}

int	is_rectangular(t_game *game, t_map *map)
{
	size_t	len;
	int		i;

	len = map->columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (ft_strlen(game->map.map[i]) != len)
		{
			free_maps(game);
			return (ft_putstr_fd(ERROR_INVALID_FORMAT, 2), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	empty_line(t_game *game, t_map *map)
{
	if (map->lines != map->line_break)
	{
		free_maps(game);
		return (ft_putstr_fd (ERROR_EMPTY_LINE, 2), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	closed_map(t_game *game, t_map *map)
{
	int	i_column;
	int	i_line;

	i_column = 0;
	i_line = 0;
	while (++i_line < map->lines)
	{
		if (game->map.map[i_line][0] != '1' ||
		game->map.map[i_line][map->columns -1] != '1')
		{
			free_maps(game);
			return (ft_putstr_fd(ERROR_MAP_NOT_CLOSED, 2), EXIT_FAILURE);
		}
	}
	while (++i_column < map->columns)
	{
		if (game->map.map[0][i_column] != '1' ||
		game->map.map[map->lines -1][i_column] != '1')
		{
			free_maps(game);
			return (ft_putstr_fd(ERROR_MAP_NOT_CLOSED, 2), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	validations(int argc, char **argv, t_game *game)
{
	t_map	map;

	if (!check_params(argc, argv))
		return (0);
	map.fd = open_file(argv[1]);
	collecting_components(map.fd, game, &map);
	if (check_components(&map))
		return (EXIT_FAILURE);
	map.fd = open_file(argv[1]);
	if (read_map(map.fd, game))
		return (EXIT_FAILURE);
	lines_and_columns(game, &map);
	if (is_rectangular(game, &map))
		return (EXIT_FAILURE);
	if (empty_line(game, &map))
		return (EXIT_FAILURE);
	if (closed_map(game, &map))
		return (EXIT_FAILURE);
	flood_fill(game, &map);
	if (game->flag != 0)
	{
		free_map(game->map.map);
		return (ft_putstr_fd(ERROR_INVALID_PATH, 2), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
