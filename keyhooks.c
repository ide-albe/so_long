/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:54:24 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/24 18:56:34 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moveplayerup(keydata, param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moveplayerright(keydata, param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		moveplayerdown(keydata, param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moveplayerleft(keydata, param);
}

void	moveplayerup(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if ((data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'E')
	{
		if (data->coins == data->total_coins)
			mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_W
		&& (data->mat[(data->pl.img->instances->y - 50) / 50]
			[(data->pl.img->instances->x) / 50].xar) != '1')
	{
		ft_printmoves(keydata, param);
		if (isacoinforw(keydata, param) == 1)
			data->coins++;
		data->pl.img->instances->y -= 50;
	}
}

void	moveplayerdown(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if ((data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'E')
	{
		if (data->coins == data->total_coins)
			mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_S
		&& (data->mat[(data->pl.img->instances->y + 50) / 50]
			[(data->pl.img->instances->x) / 50].xar) != '1')
	{
		ft_printmoves(keydata, param);
		if (isacoinfors(keydata, param) == 1)
			data->coins++;
		data->pl.img->instances->y += 50;
	}
}

void	moveplayerleft(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if ((data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'E')
	{
		if (data->coins == data->total_coins)
			mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_A
		&& (data->mat[data->pl.img->instances->y / 50]
			[(data->pl.img->instances->x - 50) / 50].xar) != '1')
	{
		ft_printmoves(keydata, param);
		if (isacoinfora(keydata, param) == 1)
			data->coins++;
		data->pl.img->instances->x -= 50;
	}
}

void	moveplayerright(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if ((data->mat[(data->pl.img->instances->y) / 50]
			[(data->pl.img->instances->x) / 50].xar) == 'E')
	{
		if (data->coins == data->total_coins)
			mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_D
		&& (data->mat[data->pl.img->instances->y / 50]
			[(data->pl.img->instances->x + 50) / 50].xar) != '1')
	{
		ft_printmoves(keydata, param);
		if (isacoinford(keydata, param) == 1)
			data->coins++;
		data->pl.img->instances->x += 50;
	}
}
