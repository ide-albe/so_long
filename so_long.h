/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:55:14 by ide-albe          #+#    #+#             */
/*   Updated: 2023/04/25 15:31:22 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include<string.h>
# include <ctype.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_mat
{
	mlx_image_t	*img;
	char		xar;
	int			f_fill;
}	t_mat;

typedef struct s_map
{
	int				width;
	int				height;
	mlx_texture_t	*background;
	mlx_texture_t	*walls;
	mlx_texture_t	*coins;
	mlx_texture_t	*exit;
}	t_map;

typedef struct s_player
{
	mlx_image_t		*img;
	mlx_texture_t	*player;
	int				pos_x;
	int				pos_y;
}	t_player;

typedef struct s_data
{
	mlx_t			*mlx;
	t_mat			**mat;
	mlx_key_data_t	keydata;
	t_player		pl;
	t_map			map;
	mlx_image_t		*img;
	int				coins;
	int				total_coins;
}	t_data;

typedef struct s_cont
{
	int		i;
	int		j;
	int		fd;
	int		nfinal;
	int		f;
	int		maplns;
	int		maplen;
}	t_cont;

int			load_background(t_mat **mat, mlx_t *mlx, t_map map);
int			load_walls(t_mat **mat, mlx_t *mlx, t_map map);
int			load_coins(t_mat **mat, mlx_t *mlx, t_map map);
int			load_exit(t_mat **mat, mlx_t *mlx, t_map map);
t_player	load_player(t_mat **mat, mlx_t *mlx, char *argv);
t_mat		**allmapcheck(t_mat **mat, t_map map, char *argv, t_player pos);
char		*mystrcpy(char	*dest, const char *src);
int			ft_strlenon(char *str);
int			linelen(char *argv);
t_mat		**reservamalloc(char *argv);
int			maplinescount(char *argv);
void		checkmapchars(char *argv);
void		mapchecklen(char *argv, t_mat **mat);
void		loadvalues(t_map map, t_mat **mat, mlx_image_t *img, mlx_t *mlx);
t_mat		**matrix(char *argv);
void		error(void);
void		checkwallsaround(t_mat **mat, t_map map);
void		mapisntvalid(void);
void		checkwallswhiles(t_mat **mat, t_cont c);
int			checkonlyoneplayer(t_mat **mat, t_map map);
t_map		valorestmap(char *argv);
void		loadmap(t_mat **mat, mlx_t *mlx, t_map map);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		hookreturn(mlx_t *mlx, t_mat **mat, t_map map);
void		hook(void *param);
t_player	player(t_mat **mat, char *argv);
void		moveplayer(mlx_key_data_t keydata, void *param);
int			totalcoins(t_mat **mat, char *argv);
int			isacoin(mlx_key_data_t keydata, void *param);
int			isacoinforw(mlx_key_data_t keydata, void *param);
int			isacoinfors(mlx_key_data_t keydata, void *param);
int			isacoinfora(mlx_key_data_t keydata, void *param);
int			isacoinford(mlx_key_data_t keydata, void *param);
void		moveplayerup(mlx_key_data_t keydata, void *param);
void		moveplayerdown(mlx_key_data_t keydata, void *param);
void		moveplayerleft(mlx_key_data_t keydata, void *param);
void		moveplayerright(mlx_key_data_t keydata, void *param);
void		ft_printmoves(mlx_key_data_t keydata, void *param);
void		cleanmatrix(void);
int			checkonlyonexit(t_mat **mat, t_map map);
void		f_fill(t_mat **matcopy, int col, int row);
t_player	playerpos(t_mat **mat, t_map map);
#endif