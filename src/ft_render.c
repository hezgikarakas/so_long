/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:41:49 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_render_sprite(t_game *game, t_img mouse, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, mouse.xpm_ptr, x
		* PIXELS, y * PIXELS);
}

static void	ft_render_mouse(t_game *game, int y, int x)
{
	if (game->look_direction == UP)
		ft_render_sprite(game, game->mouse_up, y, x);
	if (game->look_direction == DOWN)
		ft_render_sprite(game, game->mouse_down, y, x);
	if (game->look_direction == RIGHT)
		ft_render_sprite(game, game->mouse_right, y, x);
	if (game->look_direction == LEFT)
		ft_render_sprite(game, game->mouse_left, y, x);
}

static void	ft_render_sprite_at(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.map[y][x];
	if (parameter == '1')
		ft_render_sprite(game, game->wall, y, x);
	else if (parameter == '0')
		ft_render_sprite(game, game->road, y, x);
	else if (parameter == 'C')
		ft_render_sprite(game, game->cheese, y, x);
	else if (parameter == 'E')
		ft_render_sprite(game, game->exit, y, x);
	else if (parameter == 'X')
		ft_render_sprite(game, game->cat, y, x);
	else if (parameter == 'P')
		ft_render_mouse(game, y, x);
}

static void	ft_write_num_of_moves(t_game *game)
{
	char	*steps;
	char	*text;

	steps = ft_itoa(game->moves);
	if (steps == NULL)
		ft_free_and_error("Malloc error.", game);
	text = ft_strjoin("Movements : ", steps);
	if (text == NULL)
	{
		free(steps);
		ft_free_and_error("Malloc error.", game);
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 20, 0xFFFFFF, text);
	free(steps);
	free(text);
}

int	ft_render_map(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			ft_render_sprite_at(game, y, x);
			x++;
		}
		y++;
	}
	ft_write_num_of_moves(game);
	return (0);
}
