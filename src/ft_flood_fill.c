/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:27:09 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_restore(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == 'c')
				game->map.map[y][x] = 'C';
			else if (game->map.map[y][x] == 'o')
				game->map.map[y][x] = '0';
			else if (game->map.map[y][x] == 'e')
				game->map.map[y][x] = 'E';
			else if (game->map.map[y][x] == 'p')
				game->map.map[y][x] = 'P';
			else if (game->map.map[y][x] == 'x')
				game->map.map[y][x] = 'X';
			x++;
		}
		y++;
	}
}

void	ft_flood_fill(char **map, int x, int y, t_verification *pv)
{
	if (map[y][x] == '0')
		map[y][x] = 'o';
	else if (map[y][x] == 'P')
		map[y][x] = 'p';
	else if (map[y][x] == 'X')
		map[y][x] = 'x';
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'c';
		pv->reach_collectible++;
	}
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		pv->reach_exit++;
	}
	else
		return ;
	ft_flood_fill(map, x - 1, y, pv);
	ft_flood_fill(map, x + 1, y, pv);
	ft_flood_fill(map, x, y - 1, pv);
	ft_flood_fill(map, x, y + 1, pv);
}

void	ft_verify_playability(t_game *game)
{
	t_verification	v;

	v.reach_collectible = 0;
	v.reach_exit = 0;
	ft_flood_fill(game->map.map, game->map.mouse.x, game->map.mouse.y, &v);
	ft_flood_restore(game);
	if (v.reach_exit != 1)
		ft_free_and_error("Exit is not reachable.", game);
	if (v.reach_collectible != game->map.num_cheese)
		ft_free_and_error("Not all cheese is reachable.", game);
}
