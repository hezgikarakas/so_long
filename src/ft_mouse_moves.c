/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:41:32 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_or_loose_the_game(t_game *game, int new_y, int new_x)
{
	if (game->map.map[new_y][new_x] == 'E' && game->map.num_cheese == 0)
	{
		game->moves++;
		ft_win_the_game(game);
	}
	else if (game->map.map[new_y][new_x] == 'X')
	{
		game->moves++;
		ft_lost_the_game(game);
	}
}

static void	ft_mouse_moves(t_game *game, int new_y, int new_x, int direction)
{
	ft_win_or_loose_the_game(game, new_y, new_x);
	if ((game->map.map[new_y][new_x] == '0')
		|| (game->map.map[new_y][new_x] == 'C')
		|| (game->map.map[new_y][new_x] == 'E'))
	{
		game->map.map[game->map.mouse.y][game->map.mouse.x] = game->below_mouse;
		game->below_mouse = game->map.map[new_y][new_x];
		if (game->map.map[new_y][new_x] == 'C')
		{
			game->map.num_cheese--;
			game->below_mouse = '0';
		}
		game->map.mouse.x = new_x;
		game->map.mouse.y = new_y;
		game->map.map[new_y][new_x] = 'P';
		game->look_direction = direction;
		game->moves++;
		ft_render_map(game);
	}
}

int	ft_keyboard_input(int keypress, t_game *game)
{
	if (keypress == UP || keypress == W)
		ft_mouse_moves(game, game->map.mouse.y - 1, game->map.mouse.x, UP);
	if (keypress == DOWN || keypress == S)
		ft_mouse_moves(game, game->map.mouse.y + 1, game->map.mouse.x, DOWN);
	if (keypress == LEFT || keypress == A)
		ft_mouse_moves(game, game->map.mouse.y, game->map.mouse.x - 1, LEFT);
	if (keypress == RIGHT || keypress == D)
		ft_mouse_moves(game, game->map.mouse.y, game->map.mouse.x + 1, RIGHT);
	if (keypress == Q || keypress == ESC)
		ft_close_game(game);
	return (0);
}
