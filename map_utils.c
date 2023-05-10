/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:28:43 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/25 17:48:15 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapisntvalid(void)
{
	ft_printf("ERROR\nMap isn't valid!");
	exit (EXIT_FAILURE);
}

int	linelen(char *argv)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(argv, O_CREAT | O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		mapisntvalid();
	i = ft_strlen(line);
	close(fd);
	free(line);
	return (i);
}

t_mat	**reservamalloc(char *argv)
{
	t_map	map;
	int		contmalloc;
	t_mat	**all;

	map.width = linelen(argv);
	map.height = maplinescount(argv);
	contmalloc = 0;
	all = malloc(map.height * sizeof(t_mat *));
	while (contmalloc < map.height)
	{
		all[contmalloc] = malloc(map.width * sizeof(t_mat));
		contmalloc++;
	}
	return (all);
}

int	maplinescount(char *argv)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

t_map	valorestmap(char *argv)
{
	t_map	map;

	map.height = maplinescount(argv);
	map.width = linelen(argv);
	map.background = mlx_load_png("textures/grass.png");
	map.walls = mlx_load_png("textures/wall.png");
	map.coins = mlx_load_png("textures/coin.png");
	map.exit = mlx_load_png("textures/puerta.png");
	return (map);
}
