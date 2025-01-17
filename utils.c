/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:16 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 12:14:41 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Set a pixel in the image
void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	((uint32_t *)img->pixels)[y * img->width + x] = color;
}

uint32_t	combine_colours(uint8_t red, uint8_t green, uint8_t blue)
{
	t_colours	color;

	color.colrgba = (red << 24) | (green << 16) | (blue << 8) | 0x00;
	return (color.colrgba);
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include "fractol.h"

void	initial_state(t_fractol *fra)
{
	fra->zoom = 1.0;
	fra->max_it = fra->init_max;
	fra->red = 0;
	fra->green = 0;
	fra->blue = 255;
	combine_colours(fra->red, fra->green, fra->blue, fra);
}

// Set a pixel in the image
void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	((uint32_t *)img->pixels)[y * img->width + x] = color;
}

uint32_t	combine_colours(uint8_t red, uint8_t green, uint8_t blue, t_fractol *color)
{
	color->colrgba = (red << 24) | (green << 16) | (blue << 8) | 0x00;
	return (color->colrgba);
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// TODO: ft_printf

*/