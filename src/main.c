/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:46:07 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	ft_check_args(int ac, char **av, t_game *game)
{
	int	map_extension_len;

	if (ac != 2)
		ft_free_and_error("The map file must be the only argument", game);
	map_extension_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_extension_len - 4], ".ber", 4))
		ft_free_and_error("Wrong map file extention", game);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	ft_check_args(ac, av, &game);
	ft_init_map_and_count_rows(&game, av[1]);
	ft_check_map(&game);
	ft_init_mlx(&game);
	ft_init_sprites(&game);
	ft_render_map(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, ft_keyboard_input, &game);
	mlx_hook(game.win_ptr, DestroyNotify, ButtonPressMask, ft_close_game,
		&game);
	mlx_hook(game.win_ptr, Expose, ExposureMask, ft_render_map, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_all_allocated_memory(&game);
	return (0);
}
