/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:59:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/27 14:56:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_file(char *file)
{
	int	map_fd;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
		ft_putstr_fd(ERROR_MAP_OPEN, 2);
	return (map_fd);
}

int	read_file(int map_fd, t_map *map, int bytes)
{
	int	read_content;

	read_content = read(map_fd, &map->c, bytes);
	if (read_content < 0)
		ft_putstr_fd(ERROR_READING, 2);
	return (read_content);
}

void	free_map(char **clean_map)
{
	int	i;

	i = 0;
	while (clean_map[i] != NULL)
	{
		free(clean_map[i]);
		i++;
	}
	free(clean_map);
}

void	free_maps(t_game *game)
{
	free_map(game->map.map);
	free_map(game->map.clone);
}

void	ft_error(t_game *game)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	free_and_close(game);
	exit (EXIT_FAILURE);
}
