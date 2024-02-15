/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:14:38 by mbarreto          #+#    #+#             */
/*   Updated: 2024/02/05 21:14:39 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cub3d.h"

void	parse_map(t_mlx *g)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (g->m->cub[++i])
		if (g->m->cub[i][0] == ' ' || g->m->cub[i][0] == '1'
			|| g->m->cub[i][0] == 0 || g->m->cub[i][0] == '\t')
			if (x == 0)
				x = i;
	if (x == 0)
		exit(1);
	g->m->map = malloc(sizeof(char *) * (i - x + 1));
	if (!g->m->map)
		exit(1);
	i = 0;
	while (g->m->cub[x])
		g->m->map[i++] = ft_strdup(g->m->cub[x++]);
	g->m->map[i] = NULL;
}

void	map_valid(t_mlx *g)
{
	int	i;

	i = -1;
	while (g->m->cub[++i])
	{
		if (ft_strncmp(g->m->cub[i], "NO ", 3) && ft_strncmp(g->m->cub[i],
				"SO ", 3) && ft_strncmp(g->m->cub[i], "WE ", 3)
			&& ft_strncmp(g->m->cub[i], "EA ", 3) && ft_strncmp(g->m->cub[i],
				"F ", 2) && ft_strncmp(g->m->cub[i], "C ", 2)
			&& ft_strcmp(g->m->cub[i], "\n"))
			if (g->m->cub[i][0] != '1' && g->m->cub[i][0] != ' ')
				wrong_map(g);
	}
}
