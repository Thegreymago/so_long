/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:20:06 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:20:08 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	count_line(t_data *game, char *mapname)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	while (line[count])
	{
		game->size_x++;
		count++;
	}
	while (line)
	{
		game->size_y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->size_x--;
}

void	create_window(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		close_struct(game);
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->size_x * IMG_W, game->size_y * IMG_H, ".SO_long");
	if (game->win_ptr == NULL)
	{
		close_struct(game);
		exit(EXIT_FAILURE);
	}
}
