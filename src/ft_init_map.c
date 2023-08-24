/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:43:58 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checker_for_empty_line(char *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map);
	if (j == 0)
	{
		free(map);
		ft_free_and_error("The map is invalid (empty map).", game);
	}
	if (map[0] == '\n')
	{
		if (map)
			free(map);
		ft_free_and_error("The map is invalid (empty first line).", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_free_and_error("The map is invalid (empty line).", game);
		}
		i++;
	}
}

static char	*read_temporary_map(int map_fd, t_game *game)
{
	char	*map_temp;
	char	*prev_map_temp;
	char	*line_temp;

	map_temp = ft_strdup("");
	if (map_temp == NULL)
		ft_free_and_error("Malloc error.", game);
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		prev_map_temp = map_temp;
		map_temp = ft_strjoin(map_temp, line_temp);
		if (prev_map_temp)
			free(prev_map_temp);
		free(line_temp);
		if (map_temp == NULL)
			ft_free_and_error("Malloc error.", game);
		game->map.rows++;
	}
	return (map_temp);
}

void	ft_init_map_and_count_rows(t_game *game, char *av)
{
	char	*map_temp;
	int		map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_free_and_error("There is an error opening the map file.", game);
	map_temp = read_temporary_map(map_fd, game);
	close(map_fd);
	ft_checker_for_empty_line(map_temp, game);
	game->map.map = ft_split(map_temp, '\n');
	if (map_temp)
		free(map_temp);
	if (game->map.map == NULL)
		ft_free_and_error("Malloc error.", game);
}
