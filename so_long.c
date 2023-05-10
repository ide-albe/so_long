/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:58:32 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/25 17:47:49 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mat	**matrix(char *argv)
{
	t_cont	cont;
	int		fd;
	char	*line;
	t_mat	**mat;

	cont.i = 0;
	mat = reservamalloc(argv);
	cont.maplns = maplinescount(argv);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line[0] == '\n')
		mapisntvalid();
	mat[0][0].f_fill = 0;
	while (cont.i < cont.maplns)
	{
		cont.j = 0;
		while (cont.j < ft_strlenon(line))
			mat[cont.i][cont.j++].xar = line[cont.j];
		cont.i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (mat);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_player		pl;
	t_mat			**matcopy;

	if (argc == 2)
	{
		data.mat = matrix(argv[1]);
		data.map = valorestmap(argv[1]);
		pl = playerpos(data.mat, data.map);
		matcopy = allmapcheck(data.mat, data.map, argv[1], pl);
		data.coins = 0;
		data.mlx = mlx_init((data.map.width - 1) * 50,
				data.map.height * 50, "so_long", 1);
		data.img = mlx_new_image(data.mlx, data.map.width * 50,
				data.map.height * 50);
		loadmap(data.mat, data.mlx, data.map);
		data.total_coins = totalcoins(data.mat, argv[1]);
		data.pl = load_player(data.mat, data.mlx, argv[1]);
		mlx_key_hook(data.mlx, &my_keyhook, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
	}
	else
		ft_printf("ERROR\nNumber of ARGS isn't valid\nTRY: ./so_long 'map path'");
}
