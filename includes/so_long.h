/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:33:03 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:47:02 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10000

# define MOUSE_UP "./img/up.xpm"
# define MOUSE_DOWN "./img/down.xpm"
# define MOUSE_RIGHT "./img/right.xpm"
# define MOUSE_LEFT "./img/left.xpm"
# define CHEESE "./img/collect.xpm"
# define WALL "./img/wall.xpm"
# define ROAD "./img/road.xpm"
# define CAT "./img/enemy.xpm"
# define EXIT "./img/exit.xpm"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define Q 113

# define PIXELS 64

typedef struct s_img
{
	void			*xpm_ptr;
	int				x;
	int				y;
}					t_img;

typedef struct s_location
{
	int				x;
	int				y;
}					t_location;

typedef struct s_map
{
	char			**map;
	unsigned int	cols;
	unsigned int	rows;
	int				num_mouse;
	int				num_cheese;
	int				num_exit;
	t_location		mouse;
}					t_map;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				moves;
	int				look_direction;
	char			below_mouse;
	t_map			map;
	t_img			wall;
	t_img			road;
	t_img			cheese;
	t_img			cat;
	t_img			mouse_up;
	t_img			mouse_down;
	t_img			mouse_left;
	t_img			mouse_right;
	t_img			exit;
}					t_game;

typedef struct s_verification
{
	int				reach_collectible;
	int				reach_exit;
}					t_verification;

char				*get_next_line(int fd);
int					have_allocated_map(t_game *game);
void				ft_free_ptr(void **ptr);
void				ft_free_map(t_game *game);
void				ft_free_all_allocated_memory(t_game *game);
void				ft_free_and_error(char *msg, t_game *game);
void				ft_check_map(t_game *game);
void				ft_init_map_and_count_rows(t_game *game, char *av);
void				ft_init_mlx(t_game *game);
void				ft_init_sprites(t_game *game);
int					ft_render_map(t_game *game);
int					ft_win_the_game(t_game *game);
int					ft_lost_the_game(t_game *game);
int					ft_close_game(t_game *game);
int					ft_keyboard_input(int keypress, t_game *game);
void				ft_verify_playability(t_game *game);

#endif
