/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:26:32 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/25 15:31:48 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkonlyonexit(t_mat **mat, t_map map)
{
	t_cont	c;

	c.i = 0;
	c.nfinal = 0;
	while (c.i < map.height)
	{
		c.j = 0;
		while (c.j < map.width)
		{
			if (mat[c.i][c.j].xar == 'E')
				c.nfinal++;
			c.j++;
		}
		c.i++;
	}
	if (c.nfinal != 1)
	{
		ft_printf("ERROR\nThere is more than one EXIT!");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	f_fill(t_mat **matcopy, int col, int row)
{
	if (matcopy[row][col].xar == 'E' || matcopy[row][col].xar == 'C')
		matcopy[0][0].f_fill += 1;
	if (matcopy[row][col].xar == 'X' || matcopy[row][col].xar == '1')
		return ;
	matcopy[row][col].xar = 'X';
	f_fill(matcopy, col - 1, row);
	f_fill(matcopy, col, row - 1);
	f_fill(matcopy, col + 1, row);
	f_fill(matcopy, col, row + 1);
}
