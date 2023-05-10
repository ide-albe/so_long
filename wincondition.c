/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wincondition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:11 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/24 18:56:49 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	totalcoins(t_mat **mat, char *argv)
{
	int		i;
	int		j;
	int		coins;
	t_map	map;

	i = 0;
	coins = 0;
	map.height = maplinescount(argv);
	map.width = linelen(argv);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (mat[i][j].xar == 'C')
			{
				coins++;
			}
			j++;
		}
		i++;
	}
	return (coins);
}

int	isacoinforw(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W
		&& (data->mat[(data->pl.img->instances->y - 50) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'C')
	{
		data->mat[(data->pl.img->instances->y - 50) / 50]
		[(data->pl.img->instances->x) / 50].xar = '0';
		mlx_delete_image(data->mlx,
			(data->mat[(data->pl.img->instances->y - 50) / 50]
			[(data->pl.img->instances->x) / 50].img));
		return (1);
	}
	return (0);
}

int	isacoinfors(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_S
		&& (data->mat[(data->pl.img->instances->y + 50) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'C')
	{
		data->mat[(data->pl.img->instances->y + 50) / 50]
		[(data->pl.img->instances->x) / 50].xar = '0';
		mlx_delete_image(data->mlx,
			(data->mat[(data->pl.img->instances->y + 50) / 50]
			[(data->pl.img->instances->x) / 50].img));
		return (1);
	}
	return (0);
}

int	isacoinfora(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_A
		&& (data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x - 50) / 50].xar) == 'C')
	{
		data->mat[(data->pl.img->instances->y) / 50]
		[(data->pl.img->instances->x - 50) / 50].xar = '0';
		mlx_delete_image(data->mlx,
			(data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x - 50) / 50].img));
		return (1);
	}
	return (0);
}

int	isacoinford(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_D
		&& (data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x + 50) / 50].xar) == 'C')
	{
		data->mat[(data->pl.img->instances->y) / 50]
		[(data->pl.img->instances->x + 50) / 50].xar = '0';
		mlx_delete_image(data->mlx,
			(data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x + 50) / 50].img));
		return (1);
	}
	return (0);
}
