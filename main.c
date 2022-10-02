/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/02 22:05:49 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "draw.h" 
#include <assert.h>
#include "events.h"
#include "tools.h"
#include "raycast.h"

char *map[10] = {
	"1111111111",
	"1000000001",
	"1000100001",
	"1000100001",
	"1000000001",
	"10000N0001",
	"1000000001",
	"1000100001",
	"1000100001",
	"1111111111"
};

int	ft_init_vars(t_vars *vars)
{
	int		x;
	double	angle;
	
	x = 0;
	angle = 0;
	vars->ordr.dir1 = addvect(1, 1, add_color(255,0,0,0), 10);
	vars->ordr.minplane = addvect(cos(M_PI/6.0), sin(M_PI/6.0), add_color(255,0,0,0), 20);
	vars->ordr.maxplane = addvect(cos((M_PI/3.0)), sin((M_PI/3.0)), add_color(255,0,0,0), 20);	
	vars->ordr.dir1->angle = M_PI/10;
	vars->ordr.maxplane->angle = M_PI/10;
	vars->ordr.minplane->angle = M_PI/10;	
	vars->rect.color = add_color(0,0,255,0);
	vars->rect.x = 5;
	vars->rect.y = 5;
	vars->data = malloc(sizeof(t_data));
	vars->data->map = map;
	vars->data->hgt = 10;
	vars->data->wth = 10;
	return(0);
}

int    ft_init(t_vars *vars)
{
    vars->mlx = mlx_init();
	if (!vars->mlx)
		return (MLX_ERROR);
	vars->win = mlx_new_window(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "vars");
	if (!vars->win)
	{
		free(vars);
		return (MLX_ERROR);
	}
	vars->iarg->img= mlx_new_image(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->iarg->addr = mlx_get_data_addr(vars->iarg->img,
			&vars->iarg->bpp, &vars->iarg->line_len, &vars->iarg->endian);
	
	return (0);
}

int	main(void)
{
	t_vars		*vars;

	vars = allocate();
	ft_init_vars(vars);
	ft_init(vars);
	draw_map(vars);
	camera(vars);	
	mlx_put_image_to_window( vars->mlx, vars->win, vars->iarg->img, 0,0);
	mlx_key_hook(vars->win, esc_key, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_loop(vars->mlx);
}	