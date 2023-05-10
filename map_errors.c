/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:26:32 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/25 15:47:26 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmapchars(char *argv)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != 'C' && line[i] != 'P'
				&& line[i] != '0' && line[i] != 'E')
			{
				mapisntvalid();
				exit(EXIT_FAILURE);
			}
			i++;
		}
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	free (line);
}

void	mapchecklen(char *argv, t_mat **mat)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	while (mat[0][k].xar != '\0')
		k++;
	while (i < maplinescount(argv))
	{
		j = 0;
		while (mat[i][j].xar != '\0')
		{
			j++;
		}
		if (j != k)
			mapisntvalid();
		i++;
	}
}

void	checkwallsaround(t_mat **mat, t_map map)
{
	t_cont	c;

	c.i = 0;
	c.f = 1;
	while (mat[0][c.i].xar != '\n' && mat[0][c.i].xar != '\0')
	{
		if (mat[0][c.i].xar != '1')
			mapisntvalid();
		c.i++;
	}
	c.i = 0;
	while (mat[map.height - 1][c.i].xar != '\n' && mat[map.height - 1][c.i].xar)
	{
		if (mat[map.height - 1][c.i].xar != '1')
			mapisntvalid();
		c.i++;
	}
	while (c.f < map.height)
	{
		if (mat[c.f][0].xar != '1' || mat[c.f][map.width - 2].xar != '1')
			mapisntvalid();
		c.f++;
	}
}

t_mat	**allmapcheck(t_mat **mat, t_map map, char *argv, t_player pl)
{
	t_mat	**matcopy;
	int		coins;

	coins = totalcoins(mat, argv);
	matcopy = matrix(argv);
	mapchecklen(argv, mat);
	checkmapchars(argv);
	checkonlyoneplayer(mat, map);
	checkwallsaround(mat, map);
	checkonlyonexit(mat, map);
	f_fill(matcopy, pl.pos_y, pl.pos_x);
	if (matcopy[0][0].f_fill != coins + 1)
	{
		ft_printf("ERROR\nNot possible to complete the objective!");
		exit(EXIT_FAILURE);
	}
	return (matcopy);
}
