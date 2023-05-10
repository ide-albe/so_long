/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:35:08 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/24 18:21:13 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_background(t_mat **mat, mlx_t *mlx, t_map map)
{
	t_cont	c;

	c.i = 0;
	c.j = 0;
	while (c.i < map.height)
	{
		c.j = 0;
		while (c.j < map.width)
		{
			mat[c.i][c.j].img = mlx_texture_to_image(mlx, map.background);
			if (mlx_image_to_window(mlx, mat[c.i][c.j].img,
				(c.j * 50), (c.i * 50)) < 0)
				error();
			c.j++;
		}
		c.i++;
	}
	mlx_delete_texture(map.background);
	return (EXIT_SUCCESS);
}

int	load_walls(t_mat **mat, mlx_t *mlx, t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == '1')
			{
				mat[i][j].img = mlx_texture_to_image(mlx, map.walls);
				if (mlx_image_to_window(mlx, mat[i][j].img,
					(j * 50), (i * 50)) < 0)
					error();
			}
			j++;
		}
		i++;
	}
	mlx_delete_texture(map.walls);
	return (EXIT_SUCCESS);
}

int	load_coins(t_mat **mat, mlx_t *mlx, t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == 'C')
			{
				mat[i][j].img = mlx_texture_to_image(mlx, map.coins);
				if (mlx_image_to_window(mlx, mat[i][j].img,
					(j * 50), (i * 50)) < 0)
					error();
			}
			j++;
		}
		i++;
	}
	mlx_delete_texture(map.coins);
	return (EXIT_SUCCESS);
}

int	load_exit(t_mat **mat, mlx_t *mlx, t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == 'E')
			{
				mat[i][j].img = mlx_texture_to_image(mlx, map.exit);
				if (mlx_image_to_window(mlx, mat[i][j].img,
					(j * 50), (i * 50)) < 0)
					error();
			}
			j++;
		}
		i++;
	}
	mlx_delete_texture(map.exit);
	return (EXIT_SUCCESS);
}

void	loadmap(t_mat **mat, mlx_t *mlx, t_map map)
{
	load_background(mat, mlx, map);
	load_walls(mat, mlx, map);
	load_coins(mat, mlx, map);
	load_exit(mat, mlx, map);
}
