/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:47:22 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 15:35:49 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fractol
{
	char		*arg;
	int			width;
	int			height;
	int			max_it;
	int			init_max;
	double		zoom;
	double		move_x;
	double		move_y;
	mlx_image_t	*win;
	mlx_t		*mlx;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint32_t	colrgba;
}	t_fractol;

typedef struct s_numbers
{
	double		real;
	double		imag;
	double		zr;
	double		zi;
	double		tmp;
	int			y;
	int			x;
	int			it;
	int			a;
	int			b;
}	t_numbers;

void		set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void		render_mandelbrot(mlx_image_t *img, t_fractol *fractol, int max_it);
void		render_julia(mlx_image_t *img, t_fractol *fra, int max_it);
int			set_window(t_fractol *fra);
uint32_t	combine_colours(uint8_t red, uint8_t green, uint8_t blue);
int			ft_atoi(char *str);
int			ft_strcmp(char *str1, char *str2);
uint32_t	set_colours(int a, int b, int c);
int			calc_mandelbrot(int max_it, double real, double imag);
int			calc_julia(int max_it, double real, double imag);
void		acquisition(mlx_image_t *win, t_fractol *fractol);
void		scrollhook(double xdelta, double ydelta, void *param);
void		keyhook(mlx_key_data_t keydata, void *param);
void		initial_state(t_fractol *fra);

#endif