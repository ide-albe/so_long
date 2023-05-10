/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:24:34 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/24 16:53:16 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*mystrcpy(char	*dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlenon(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_printmoves(mlx_key_data_t keydata, void *param)
{
	t_data		*data;
	static int	moves;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		moves++;
		ft_printf("%i\n", moves);
	}
}

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
