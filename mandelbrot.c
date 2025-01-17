/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:52 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 12:20:20 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Map pixel (x, y) to complex plane between -2 and 2 with x on 0
// Mandelbrot pixels in the complex plane
// Map it to color
// Combine into an RGBA color
// fra = fractol, max_it = max iteration
// a = colour redention depending on iteration number
// b = width of the image depending on the zoom
void	render_mandelbrot(mlx_image_t *img, t_fractol *fra, int max_it)
{
	t_numbers	num;
	t_colours	colours;

	num.y = 0;
	while (num.y < (int)img->height)
	{
		num.x = 0;
		num.a = 0;
		while (num.x < (int)img->width)
		{
			num.b = img->width * fra->zoom;
			num.real = (num.x - img->width / 2.0) * 4.0 / num.b;
			num.imag = (num.y - img->height / 2.0) * 4.0 / num.b;
			num.it = calc(max_it, num.real, num.imag);
			num.a = (255 * num.it) / max_it;
			if (num.it == max_it)
				colours.colrgba = set_colours(255, 0, 0);
			else
				colours.colrgba = set_colours(num.a, num.a, 0);
			set_pixel(img, num.x, num.y, colours.colrgba);
			num.x++;
		}
		num.y++;
	}
}

uint32_t	set_colours(int a, int b, int c)
{
	t_colours	color;

	color.red = a;
	color.green = b;
	color.blue = c;
	color.colrgba = 0;
	color.colrgba = combine_colours(color.red, color.green, color.blue);
	return (color.colrgba);
}

int	calc(int max_it, double real, double imag)
{
	double			tmp;
	t_numbers		num;

	num.zr = 0.0;
	num.zi = 0.0;
	num.it = 0.0;
	tmp = 0.0;
	while (num.zr * num.zr + num.zi * num.zi <= 4.0 && num.it < max_it)
	{
		tmp = num.zr * num.zr - num.zi * num.zi + real;
		num.zi = 2.0 * num.zr * num.zi + imag;
		num.zr = tmp;
		num.it++;
	}
	return (num.it);
}
