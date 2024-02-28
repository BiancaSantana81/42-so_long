/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:14:15 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 15:21:59 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 10
# define SIZE 16
# define ZOOM 4
# define BLOCK 64

// INCLUDES

# include "../inc/error_messages.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// STRUCTS

/* Struct to store MLX image pointers for the map */
typedef struct s_sprite
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int32_t			x;
	int32_t			y;
}	t_sprite;

/* Structure to store variables on the map structure*/
typedef struct s_map
{
	char	**map;
	char	**clone;
	char	c[1];
	int		fd;
	int		bytes_read;
	int		count_bytes;
	int		lines;
	int		columns;
	int		n_collectible;
	int		n_exit;
	int		n_player;
	int		invalid_character;
	int		line_break;
}	t_map;

/* Struct to store game attributes */
typedef struct s_game
{
	mlx_t		*mlx;
	char		buffer[BUFFER_SIZE + 1];
	int			flag;
	int			line;
	int			column;
	int			count_fire;
	int			count_collectible;
	int			remove_collectible;
	int			player_x;
	int			player_y;
	int			n_moves;
	t_map		map;
	mlx_image_t	*steps;
	mlx_image_t	*count_image;
	t_sprite	*counter;
	t_sprite	*player_data;
	t_sprite	*floor;
	t_sprite	*rock;
	t_sprite	*exit;
	t_sprite	*hudson_still;
	t_sprite	*apple;
	t_sprite	*fire;
}	t_game;

/***** map functions *****/

/* Initializes the map variables */
void		init_struct_map(t_map *map);

/* Initializes the game variables */
void		init_struct(t_game *game);

/* Auxiliary function: opens the fd containing the map.  */
int			open_file(char *file);

/* Auxiliary function: reads the file passed as a parameter. */
int			read_file(int map_fd, t_map *map, int bytes);

/* Collects the map components in struct map */
void		collecting_components(int map_fd, t_game *game, t_map *map);

/* Reads the map, transforms it into
a matrix and stores it in game->map.map */
int			read_map(int map_fd, t_game *game);

/* Counts rows and columns and stores value in my struct */
void		lines_and_columns(t_game *game, t_map *map);

/* Clean each of the map elements and the map. */
void		free_map(char **clean_map);

/* Call free_map to clear the main map and the clone map. */
void		free_maps(t_game *game);

/***** validation functions *****/

/* Basic checks to ensure that the map is opened. */
int			check_params(int argc, char **argv);

/* Organize all the validations before starting the graphic part of the game. */
int			validations(int argc, char **argv, t_game *game);

/* Checks the correct number of map components. */
int			check_components(t_map *map);

/* Checks if the map is rectangular. */
int			is_rectangular(t_game *game, t_map *map);

/* Check for empty lines on the map. */
int			empty_line(t_game *game, t_map *map);

/* Checks if the map is enclosed by walls. */
int			closed_map(t_game *game, t_map *map);

/* Flood fill algorithm. Fills all visited positions with the value 1. */
void		aux_flood_fill(t_game *game, t_map *map, int x, int y);

/* Checks the quantity of clone components after flood fill. */
int			check_clone(t_game *game);

/* Find the position of P, call the flood
fill algorithm and the check_clone function. */
void		flood_fill(t_game *game, t_map *map);

/***** functions graphic part *****/

/* Initializes the game after validations. */
int			init_game(t_game *game);

/* Loading information needed to add images to the screen. */
void		get_images(t_game *game);
/* Loading texture paths and transforming them into images. */

t_sprite	*load_images(t_game	*game, char *path);

/** Set of functions that add images of game components to the window. **/

int			draw_hudson_still(t_game *game);
int			draw_apples(t_game *game, int x, int y);
int			draw_rock(t_game *game, int x, int y);
int			draw_exit(t_game *game, int x, int y);
int			draw_fire(t_game *game, int x, int y);

/* Auxiliary function: draws images in the window. */
void		aux_draw_images(t_game *game, int line, int column);

/* Drawing the images on the game map. */
int			draw_images(t_game *game);

/* Adds a background image to the counter with the word "Moves: ". */
int			build_counter(t_game *game);

/* Adds the step counter to the window. */
void		counter(t_game *game);

/* Data on selected keys. */
int32_t		key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2);
/* Captures the movement requested by the player. */
void		requested_movements(mlx_key_data_t keydata, void *param);

/* Player movement on the x axis. */
void		player_movement_x(t_game *game, char pos, char op);

/* Player movement on the y axis. */
void		player_movement_y(t_game *game, char pos, char op);

/* After the player passes the collectible,
disable its image and update the count. */
void		updated_collectibles(t_game *game);

/* After the player collects collectibles, enable the exit and end the game. */
void		end_of_game(t_game *game);

/* If you touch the fire, the player loses. */
int			game_over(t_game *game);

/* Clears all textures and images from the game and closes the window. */
void		free_and_close(void *param);

/* Auxiliary function: cleans textures and images. */
void		free_sprites(t_game *game, t_sprite *sprites);

/* Auxiliary function: clears and closes the
game in the event of an error when loading a texture/image. */
void		ft_error(t_game *game);


#endif
