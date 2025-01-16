#include "fractol.h"

void scrollhook(double xdelta, double ydelta, void* param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = param;
	// Simple up or down detection.
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
	
	render_mandelbrot(fractol->win, fractol, fractol->max_it);
}
