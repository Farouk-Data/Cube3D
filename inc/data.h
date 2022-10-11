/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:01:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/10 23:26:19 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>

typedef enum e_NSWE
{
    NO,
    SO,
    WE,
    EA
}   t_nswe;

typedef struct s_txtpath
{
    char    *path;	
    t_nswe  nswe; 
}   t_txtpath;

typedef struct s_color
{
    unsigned int    rd;
    unsigned int    gr;
    unsigned int    bl;
}   t_color;

typedef struct s_data
{
    int         *wth;
    int         hgt;
    t_txtpath   *txtpath; 
    char        **map;
}   t_data;

typedef struct s_imgarg
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgarg;

typedef struct s_vector
{
	double	x;
	double	y;
	double	angle;
	double	mag;
	t_color	color;
}	t_vector;

typedef struct s_org_dir
{
	t_vector	*origin;
	t_vector	*dir1;
	t_vector	*minplane;
	t_vector	*maxplane;	
}	t_org_dir;

typedef struct  s_rect
{
	double	x;
	double	y;
	t_color color;
}	t_rect;

typedef	struct s_point
{
	int	px;
	int	py;
}	t_point;


typedef struct s_inter
{
	t_vector	current_pos;
	t_point		pos_grid;
	t_point		next_pos;
	t_point		next_pos_grid;
	double		dx;
	double		dy;
	double		final_d;
	int			sign_x;	
	int			sign_y;
	int			is_inters;	
}	t_inters;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	origin;
	t_inters	inters;
	int			is_vertical;
}	t_ray;

typedef struct	s_texture
{
	int 		width;
	int 		height;
	char 		*path;
	t_imgarg	ig;
}	t_texture;

typedef struct	s_vars 
{
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_data		*data;
    t_texture	txtre;
	t_org_dir	ordr;
	t_rect		rect;
	t_ray		ray;
	t_color		ceil;
	t_color		floor;
	unsigned int	*wall_text;
}	t_vars;

typedef struct s_pars 
{
    int     i;
    int     j;
    int     fd;
    int     col;
    int     count;
    char    *line;
    char    **tmp;
}   t_pars;

#endif