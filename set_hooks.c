/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:32:45 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 14:54:58 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = param;
	if (ydelta > 0)
	{
		puts("Up!");
		fractol->zoom *= 2;
	}
	else if (ydelta < 0)
	{
		puts("Down!");
		fractol->zoom /= 2;
	}
	acquisition(fractol->win, fractol);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		fractol->arg = "j";
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		fractol->arg = "m";
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		fractol->max_it += 5;
		printf("max_it = %i\n", fractol->max_it);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		fractol->max_it -= 5;
		if (fractol->max_it <= 1)
			fractol->max_it = 2;
		printf("max_it = %i\n", fractol->max_it);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		initial_state(fractol);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
	{
		fractol->red += 10;
		printf("red = %i\n", fractol->red);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_G && keydata.action == MLX_PRESS)
	{
		fractol->green += 10;
		printf("green = %i\n", fractol->green);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
	{
		fractol->blue += 10;
		printf("blue = %i\n", fractol->blue);
		acquisition(fractol->win, fractol);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		if (fractol->win)
		{
			mlx_delete_image(fractol->mlx, fractol->win);
			fractol->win = NULL;
		}
		if (fractol->mlx)
		{
			mlx_terminate(fractol->mlx);
			fractol->mlx = NULL;
		}
		exit(0);
	}
}

void	initial_state(t_fractol *fra)
{
	fra->zoom = 1.0;
	fra->max_it = fra->init_max;
	fra->red = 255;
	fra->green = 255;
	fra->blue = 255;
	fra->colrgba = combine_colours(fra->red, fra->green, fra->blue);
}

//void scrollhook(double xdelta, double ydelta, void* param)
//{
//	t_fractol	*fractol;
//	int32_t		mouse_x;
//	int32_t		mouse_y;
//	double		mouse_real;
//	double		mouse_imag;

//	(void)xdelta;
//	fractol = param;
//	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
//	mouse_real = (mouse_x - fractol->width / 2.0) * 4.0 / (fractol->width * fractol->zoom) + fractol->move_x;
//	mouse_imag = (mouse_y - fractol->height / 2.0) * 4.0 / (fractol->height * fractol->zoom) + fractol->move_y;
//	if (ydelta > 0)
//	{
//		puts("Up!");
//		fractol->zoom *= 2;
//	}
//	else if (ydelta < 0)
//	{
//		puts("Down!");
//		fractol->zoom /= 2;
//	}
//	fractol->move_x = mouse_real - (mouse_x - fractol->width / 2.0) * 4.0 / (fractol->width * fractol->zoom);
//	fractol->move_y = mouse_imag - (mouse_y - fractol->height / 2.0) * 4.0 / (fractol->height * fractol->zoom);
//	render_mandelbrot(fractol->win, fractol, fractol->max_it);
//}
