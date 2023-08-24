/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 08:25:16 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	have_allocated_map(t_game *game)
{
	if (game->map.map != NULL)
		return (1);
	else
		return (0);
}

void	ft_free_map(t_game *game)
{
	unsigned int	line;

	if (!have_allocated_map(game))
		return ;
	line = 0;
	while (line < game->map.rows && game->map.map[line])
		if (game->map.map[line])
			free(game->map.map[line++]);
	if (game->map.map)
		free(game->map.map);
	game->map.map = NULL;
}
