/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 12:08:08 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initialize MLX42
// Create an image
// render mandelbrot or julia
// Display the image in the window
int	set_window(t_fractol *fractol, char *arg, t_engine *engine)
{
	fractol->zoom = 1.0;
	// fractol->move_x = 1.0;
	// fractol->move_y = 1.0;
	t_engine	en;

	en = *engine;
	en.mlx = mlx_init(fractol->width, fractol->height, "Fractal", true);
	if (!en.mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return (EXIT_FAILURE);
	}
	en.win = mlx_new_image(en.mlx, fractol->width, fractol->height);
	if (!en.win)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(en.mlx);
		return (EXIT_FAILURE);
	}
	fractol->win = en.win;
	acquisition(arg, en.win, fractol);
	mlx_image_to_window(en.mlx, en.win, 0, 0);
mlx_scroll_hook(en.mlx, &scrollhook, fractol);
	mlx_loop(en.mlx);
	mlx_delete_image(en.mlx, en.win);
	mlx_terminate(en.mlx);
	return (EXIT_SUCCESS);
}

void	acquisition(char *arg, mlx_image_t *win, t_fractol *fractol)
{
	if (ft_strcmp(arg, "m") == 0)
		render_mandelbrot(win, fractol, fractol->max_it);
	else if (ft_strcmp(arg, "j") == 0)
		render_julia(win, fractol->max_it);
}
