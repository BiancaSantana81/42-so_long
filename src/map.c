/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:16:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 11:53:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collecting_components(int map_fd, t_game *game, t_map *map)
{
	init_struct_map(map);
	map->bytes_read = read_file(map_fd, map, 1);
	while (map->bytes_read > 0)
	{
		if (map->c[0])
			map->count_bytes++;
		if (map->c[0] == 'P')
			map->n_player++;
		else if (map->c[0] == 'C')
			map->n_collectible++;
		else if (map->c[0] == 'E')
			map->n_exit++;
		else if (map->c[0] == 'F')
			game->count_fire++;
		else if (map->c[0] == '\n')
			map->line_break++;
		else if (map->c[0] != 'P' && map->c[0] != 'C'
			&& map->c[0] != 'E' && map->c[0] != '0'
			&& map->c[0] != '1' && map->c[0] != '\n' && map->c[0] != 'F')
			map->invalid_character++;
		map->bytes_read = read_file(map_fd, map, 1);
	}
	game->count_collectible = map->n_collectible;
	game->remove_collectible = map->n_collectible;
	close(map_fd);
}

int	check_components(t_map *map)
{
	if (map->count_bytes < 17)
		return (ft_putstr_fd(ERROR_MAP, 2), EXIT_FAILURE);
	if (map->n_exit != 1)
		return (ft_putstr_fd(ERROR_EXIT, 2), EXIT_FAILURE);
	if (map->n_player != 1)
		return (ft_putstr_fd(ERROR_PLAYER, 2), EXIT_FAILURE);
	if (map->n_collectible < 1)
		return (ft_putstr_fd(ERROR_COLLECTIBLE, 2), EXIT_FAILURE);
	if (map->invalid_character > 0)
		return (ft_putstr_fd(ERROR_CHARACTER, 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_map(int map_fd, t_game *game)
{
	int			readcount;
	char		*tmp;
	char		*map_read;

	map_read = ft_calloc(1, sizeof(char));
	readcount = read(map_fd, game->buffer, 10);
	if (readcount < 0)
		return (ft_putstr_fd(ERROR_READING, 2), EXIT_FAILURE);
	while (readcount > 0)
	{
		game->buffer[readcount] = '\0';
		tmp = ft_strjoin(map_read, game->buffer);
		free(map_read);
		map_read = tmp;
		readcount = read(map_fd, game->buffer, 10);
	}
	close(map_fd);
	game->map.map = ft_split(map_read, '\n');
	game->map.clone = ft_split(map_read, '\n');
	free(map_read);
	return (EXIT_SUCCESS);
}

void	lines_and_columns(t_game *game, t_map *map)
{
	int	lines;
	int	columns;

	lines = 0;
	columns = 0;
	while (game->map.map[lines] != NULL)
	{
		if (lines == 0)
			columns = ft_strlen(game->map.map[lines]);
		lines++;
	}
	map->lines = lines;
	map->columns = columns;
	game->line = lines;
	game->column = columns;
}
