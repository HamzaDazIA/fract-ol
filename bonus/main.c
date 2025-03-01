/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:03 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 04:43:18 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage(void)
{
	write(1, "\nUsage:\n", 9);
	write(1, "fractol <fractal_type>\n\n", 25);
	write(1, "Available fractals:\n\n", 22);
	write(1, "🌀 mandelbrot\n", 17);
	write(1, "🌊 julia <real> <imag>\n", 26);
	write(1, "🔥 multibrot\n\n", 17);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (HEIGHT <= 0 || HEIGHT > 2500 || WIDTH <= 0 || WIDTH > 2500 || argc < 2)
		return (1);
	if (N_MAX > 2 || N_MAX < -2 || N_MIN < -2 || N_MIN > 2) // check this in the parins part 
		return (1);
	if (parsin(argc, argv, &data) == 0)
	{
		print_usage();
		return (1);
	}
	else if (mlx_conialization(&data) == 1)
	{
		write(2, "Error initializing MiniLibX\n", 28);
		return (1);
	}
	data.number = 0;
	do_fractol(&data);
	mlx_key_hook(data.mlx_win, key_events, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_mouse_hook(data.mlx_win, mouse_zoom, &data);
	mlx_loop(data.mlx_con);
	return (0);
}
