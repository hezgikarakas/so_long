/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:00:31 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_rows(t_game *game)
{
	unsigned int	i;
	unsigned int	rowlen;

	if (game->map.rows < 3)
		ft_free_and_error("Map needs 3 rows or no space for stuff.", game);
	i = 0;
	while (i < game->map.rows)
	{
		rowlen = ft_strlen(game->map.map[i]);
		if (rowlen < game->map.cols)
			ft_free_and_error("Invalid map (short row).", game);
		if (rowlen > game->map.cols + 1)
			ft_free_and_error("Invalid map (long row).", game);
		if (game->map.map[i][0] != '1')
			ft_free_and_error("Invalid map (missing left wall).", game);
		if (game->map.map[i][game->map.cols - 1] != '1')
			ft_free_and_error("Invalid map (missing right wall).", game);
		i++;
	}
}

static void	ft_check_cols(t_game *game)
{
	unsigned int	i;

	if (game->map.cols < 3)
		ft_free_and_error("Map needs 3 cols or no space for stuff.", game);
	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.map[0][i] != '1')
			ft_free_and_error("Invalid map (missing upper wall).", game);
		else if (game->map.map[game->map.rows - 1][i] != '1')
			ft_free_and_error("Invalid map (missing lower wall).", game);
		i++;
	}
}

static void	ft_check_map_items(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (!ft_strchr("CEPX01", game->map.map[y][x]))
				ft_free_and_error("Invalid character in the map.", game);
			else if (game->map.map[y][x] == 'P')
			{
				game->map.num_mouse++;
				game->map.mouse.x = x;
				game->map.mouse.y = y;
			}
			else if (game->map.map[y][x] == 'C')
				game->map.num_cheese++;
			else if (game->map.map[y][x] == 'E')
				game->map.num_exit++;
			x++;
		}
		y++;
	}
}

static void	ft_verify_map_items(t_game *game)
{
	if (game->map.num_mouse != 1)
		ft_free_and_error("There must be only one mouse!", game);
	else if (game->map.num_exit != 1)
		ft_free_and_error("There must be only one exit!", game);
	else if (game->map.num_cheese == 0)
		ft_free_and_error("Sadly, there is no cheese.", game);
}

void	ft_check_map(t_game *game)
{
	game->map.cols = ft_strlen(game->map.map[0]);
	ft_check_rows(game);
	ft_check_cols(game);
	ft_check_map_items(game);
	ft_verify_map_items(game);
	ft_verify_playability(game);
	game->look_direction = RIGHT;
	game->below_mouse = '0';
}
