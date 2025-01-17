/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:00:39 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 16:23:51 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// z = z2 + c where c is a constant given for the set

void	render_julia(mlx_image_t *img, t_fractol *fra, int max_it)
{
	t_numbers	num;

	num.y = 0;
	while (num.y < (int)img->height)
	{
		num.x = 0;
		while (num.x < (int)img->width)
		{
			num.b = img->width * fra->zoom;
			num.real = (num.x - img->width / 2.0) * 4.0 / num.b;
			num.imag = (num.y - img->height / 2.0) * 4.0 / num.b;
			num.it = calc_julia(max_it, num.real, num.imag);
			if (num.it == max_it)
				fra->colrgba = set_colours(0, 0, 0);
			else
				fra->colrgba = set_colours(fra->red * num.it, fra->green * num.it, fra->blue * num.it);
			set_pixel(img, num.x, num.y, fra->colrgba);
			num.x++;
		}
		num.y++;
	}
}

int	calc_julia(int max_it, double real, double imag)
{
	double			tmp;
	t_numbers		num;
	double			cr;
	double			ci;

	cr = 0.79;
	ci = 0.55;
	num.zr = real;
	num.zi = imag;
	num.it = 0.0;
	tmp = 0.0;
	while (num.zr * num.zr + num.zi * num.zi <= 4.0 && num.it < max_it)
	{
		tmp = num.zr * num.zr - num.zi * num.zi + cr;
		num.zi = 2 * num.zr * num.zi + ci;
		num.zr = tmp;
		num.it++;
	}
	return (num.it);
}

//uint32_t	set_colours(int a, int b, int c)
//{
//	t_colours	color;

//	color.red = a;
//	color.green = b;
//	color.blue = c;
//	color.colrgba = 0;
//	color.colrgba = combine_colours(color.red, color.green, color.blue);
//	return (color.colrgba);
//}

//int	calc(int max_it, double real, double imag)
//{
//	double			tmp;
//	t_numbers		num;

//	num.zr = 0.0;
//	num.zi = 0.0;
//	num.it = 0.0;
//	tmp = 0.0;
//	while (num.zr * num.zr + num.zi * num.zi <= 4.0 && num.it < max_it)
//	{
//		tmp = num.zr * num.zr - num.zi * num.zi + real;
//		num.zi = 2.0 * num.zr * num.zi + imag;
//		num.zr = tmp;
//		num.it++;
//	}
//	return (num.it);
//}

//void	render_julia(mlx_image_t *img, t_fractol *fra, int max_it)
//{
//	int			y;
//	int			x;
//	int			it;
//	t_numbers	num;
//	t_colours	color;

//	(void)fra;
//	y = 0;
//	while (y < (int)img->height)
//	{
//		x = 0;
//		while (x < (int)img->width)
//		{
//	// Map pixel (x, y) to complex plane between -2 and 2 with x on 0
//			num.real = (x - img->width / 2.0) * 4.0 / img->width;
//			num.imag = (y - img->height / 2.0) * 4.0 / img->width;
//			num.zr = 0.0;
//			num.zi = 0.0;
//			it = 0;
//	// Mandelbrot it
//			while (num.zr * num.zr + num.zi * num.zi <= 4.0 && it < max_it)
//			{
//				num.tmp = num.zr * num.zr - num.zi * num.zi + num.real;
//				num.zi = 2.0 * num.zr * num.zi + num.imag;
//				num.zr = num.tmp;
//				it++;
//			}
//	// Map it to color
//			if (it == max_it)
//			{
//				color.red = 0;
//				color.green = 0;
//				color.blue = 255;
//			}
//			else
//			{
//				color.red = (255 * it) / max_it;
//				color.green = (255 * it) / max_it;
//				color.blue = 255;
//			}
//	// Combine into an RGBA color
//			color.colrgba = combine_colours(color.red, color.green, color.blue);
//			set_pixel(img, x, y, color.colrgba);
//			x++;
//		}
//		y++;
//	}
//}
