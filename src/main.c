/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:14:35 by mbarreto          #+#    #+#             */
/*   Updated: 2024/02/05 21:14:36 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

int	refresh_screen(t_mlx *mlx)
{
	cast_rays(mlx);
	render_gun(mlx);
	if (mlx->map_enabled)
		displaymap(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->mlx_win, mlx->img, 0, 0);
	mlx_do_sync(mlx->ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc > 2)
	{
		printf("Too many arguments\n");
		exit(1);
	}
	map_parser(argc, argv, &mlx);
	init_libmlx(&mlx);
	mlx.p = init_player(mlx.p, mlx.m);
	refresh_screen(&mlx);
	mlx_loop(mlx.ptr);
	free_map(&mlx);
	return (1);
}
