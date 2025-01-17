/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 12:21:18 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initialize MLX42
// Create an image
// render mandelbrot or julia
// Display the image in the window
int	set_window(t_fractol *fra)
{
	fra->zoom = 1.0;
	fra->mlx = mlx_init(fra->width, fra->height, "Fractal", true);
	if (!fra->mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return (EXIT_FAILURE);
	}
	fra->win = mlx_new_image(fra->mlx, fra->width, fra->height);
	if (!fra->win)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(fra->mlx);
		return (EXIT_FAILURE);
	}
	fra->win = fra->win;
	acquisition(fra->win, fra);
	mlx_image_to_window(fra->mlx, fra->win, 0, 0);
	mlx_scroll_hook(fra->mlx, &scrollhook, fra);
	mlx_key_hook(fra->mlx, &keyhook, fra);
	mlx_loop(fra->mlx);
	mlx_delete_image(fra->mlx, fra->win);
	mlx_terminate(fra->mlx);
	return (EXIT_SUCCESS);
}

void	acquisition(mlx_image_t *win, t_fractol *fractol)
{
	if (ft_strcmp(fractol->arg, "m") == 0)
		render_mandelbrot(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "j") == 0)
		render_julia(win, fractol, fractol->max_it);
}
