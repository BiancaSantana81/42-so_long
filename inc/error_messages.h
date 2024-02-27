/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/27 18:04:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# include "../inc/so_long.h"

# define ERROR_MAP "Invalid map!"
# define ERROR_ARGS "Invalid arguments!"
# define ERROR_EXTENSION "Invalid extension, use the .ber file type."
# define ERROR_MAP_OPEN "The map could not be opened."
# define ERROR_READING "Error reading."
# define ERROR_PLAYER "The game should only have one player!"
# define ERROR_EXIT "The game must have only one exit!"
# define ERROR_COLLECTIBLE "The game must have at least one collectible."
# define ERROR_CHARACTER "Invalid character in the map!"
# define ERROR_EMPTY_LINE "One or more empty lines on the map."
# define ERROR_INVALID_FORMAT "The map format is invalid."
# define ERROR_MAP_NOT_CLOSED "Map without closed walls."
# define ERROR_INVALID_PATH "The game is invalid!"

#endif