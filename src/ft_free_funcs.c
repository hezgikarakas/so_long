/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:46:58 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	ft_destroy_image_if_not_null(void *mlx, void *img)
{
	if (img != NULL)
	{
		mlx_destroy_image(mlx, img);
	}
}

void	ft_destroy_images(t_game *game)
{
	if (game->mlx_ptr != NULL)
	{
		ft_destroy_image_if_not_null(game->mlx_ptr, game->wall.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->road.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->cheese.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->mouse_up.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->mouse_down.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->mouse_left.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->mouse_right.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->cat.xpm_ptr);
		ft_destroy_image_if_not_null(game->mlx_ptr, game->exit.xpm_ptr);
	}
}

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	if (game->mlx_ptr != NULL)
	{
		if (game->win_ptr != NULL)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		ft_free_ptr(&game->mlx_ptr);
	}
}

void	ft_free_and_error(char *msg, t_game *game)
{
	ft_free_all_allocated_memory(game);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
