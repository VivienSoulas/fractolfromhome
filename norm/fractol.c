/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:47:00 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fractol.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vsoulas <vsoulas@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/06 14:53:18 by vsoulas		   #+#	#+#			 */
/*   Updated: 2024/12/13 13:20:22 by vsoulas		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_engine	engine;

	if (argc != 5)
	{
		printf("Please indicate <max iteration> <length> <height>\n");
		printf("For Mandelbrot <m>\nFor Julia <j>\n");
		return (-1);
	}
	if (ft_strcmp(argv[4], "m") != 0 && ft_strcmp(argv[4], "j") != 0)
	{
		printf("Please indicate <m> for Mandelbrot or <j> for Julia\n");
		return (-1);
	}
	fractol.max_it = ft_atoi(argv[1]);
	fractol.width = ft_atoi(argv[2]);
	fractol.height = ft_atoi(argv[3]);
	set_window(&fractol, argv[4], &engine);
	return (EXIT_SUCCESS);
}
