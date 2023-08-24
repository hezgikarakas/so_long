/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:47:17 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_free_and_error("Problem initializing mlx.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.cols * 64,
			game->map.rows * 64, "so_long");
	if (game && game->win_ptr == NULL)
	{
		if (game->mlx_ptr)
			free(game->mlx_ptr);
		ft_free_and_error("Problem while creating window", game);
	}
}

static t_img	ft_add_img(char *path, t_game *game)
{
	t_img	image;

	image.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &image.x,
			&image.y);
	if (image.xpm_ptr == NULL)
		ft_free_and_error("Problem while loading XPM files", game);
	return (image);
}

void	ft_init_sprites(t_game *game)
{
	game->wall = ft_add_img(WALL, game);
	game->road = ft_add_img(ROAD, game);
	game->cheese = ft_add_img(CHEESE, game);
	game->mouse_up = ft_add_img(MOUSE_UP, game);
	game->mouse_down = ft_add_img(MOUSE_DOWN, game);
	game->mouse_right = ft_add_img(MOUSE_RIGHT, game);
	game->mouse_left = ft_add_img(MOUSE_LEFT, game);
	game->cat = ft_add_img(CAT, game);
	game->exit = ft_add_img(EXIT, game);
}
