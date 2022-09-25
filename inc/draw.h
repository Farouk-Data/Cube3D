/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 04:54:30 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR	1

#include "parsing.h"
typedef struct s_imgarg
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgarg;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_data		*data;
}	t_vars;

typedef struct s_vector
{
	double	x;
	double	y;
	t_color	*color;
}	t_vector;

typedef struct s_rect
{
	t_vector	*vrect;
	int			width;
	int			height;
}	t_rect;

void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data,t_vector *v, t_vector *vfix, double rad);
void	draw_rect(t_vars *data, t_rect *rect);

#endif