/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:00:31 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_write_moves(t_game *game)
{
	ft_putstr_fd("Movements: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

int	ft_win_the_game(t_game *game)
{
	ft_write_moves(game);
	ft_free_all_allocated_memory(game);
	ft_putstr_fd("CONGRATULATIONS! YOU WIN!\n", 1);
	exit(0);
}

int	ft_lost_the_game(t_game *game)
{
	ft_write_moves(game);
	ft_free_all_allocated_memory(game);
	ft_putstr_fd("OH YO! YOU LOST THE GAME!\n", 1);
	exit(0);
}

int	ft_close_game(t_game *game)
{
	ft_write_moves(game);
	ft_free_all_allocated_memory(game);
	ft_putstr_fd("YOU CLOSED THE GAME\n", 1);
	exit(0);
}
