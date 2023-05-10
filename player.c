/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:35:21 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/24 18:34:44 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkonlyoneplayer(t_mat **mat, t_map map)
{
	t_cont	c;

	c.i = 0;
	c.nfinal = 0;
	while (c.i < map.height)
	{
		c.j = 0;
		while (c.j < map.width)
		{
			if (mat[c.i][c.j].xar == 'P')
				c.nfinal++;
			c.j++;
		}
		c.i++;
	}
	if (c.nfinal != 1)
	{
		ft_printf("ERROR\nThere is more than one PLAYER active!");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_player	load_player(t_mat **mat, mlx_t *mlx, char *argv)
{
	t_player	pl;

	pl = player(mat, argv);
	pl.img = mlx_new_image(mlx, 50, 50);
	pl.img = mlx_texture_to_image(mlx, pl.player);
	if (mlx_image_to_window(mlx, pl.img, (pl.pos_y * 50), (pl.pos_x * 50)) < 0)
		error();
	return (pl);
}

t_player	player(t_mat **mat, char *argv)
{
	int			i;
	int			j;
	t_map		map;
	t_player	pl;

	i = 0;
	map.height = maplinescount(argv);
	map.width = linelen(argv);
	pl.player = mlx_load_png("textures/Player.png");
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == 'P')
			{
				pl.pos_x = i;
				pl.pos_y = j;
			}
			j++;
		}
		i++;
	}
	return (pl);
}

t_player	playerpos(t_mat **mat, t_map map)
{
	int			i;
	int			j;
	t_player	pl;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == 'P')
			{
				pl.pos_x = i;
				pl.pos_y = j;
			}
			j++;
		}
		i++;
	}
	return (pl);
}
