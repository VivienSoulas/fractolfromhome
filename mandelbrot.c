/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:52 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 12:12:50 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Map pixel (x, y) to complex plane between -2 and 2 with x on 0
// Mandelbrot pixels in the complex plane
// Map it to color
// Combine into an RGBA color
void	render_mandelbrot(mlx_image_t *img, t_fractol *fractol, int max_it)
{
	t_numbers	num;
	uint32_t	colour;
	int			a;

	colour = 0;
	num.y = 0;
	while (num.y < (int)img->height)
	{
		num.x = 0;
		a = 0;
		while (num.x < (int)img->width)
		{
			num.real = (num.x - img->width / 2.0) * 4.0 / (img->width * fractol->zoom);
			num.imag = (num.y - img->height / 2.0) * 4.0 / (img->width * fractol->zoom);
			num.it = calc(max_it, num.real, num.imag);
			a = (255 * num.it) / max_it;
			if (num.it == max_it)
				colour = set_colours(255, 0, 0);
			else
				colour = set_colours(a, a, 0);
			set_pixel(img, num.x, num.y, colour);
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
