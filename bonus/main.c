/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:03 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/04 00:11:46 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage_bonus(void)
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

	if (HEIGHT <= 0 || HEIGHT > 2500 || WIDTH <= 0 || WIDTH > 2500)
		return (1);
	else if (N_MAX > 2 || N_MAX < -2 || N_MIN < -2 || N_MIN > 2)
		return (1);
	else if (argc < 2)
		print_usage_bonus();
	else if (parsin_bonus(argc, argv, &data) == 0)
		print_usage_bonus();
	else if (mlx_initialization_bonus(&data) == 1)
	{
		write(2, "Error initializing MiniLibX\n", 28);
		return (1);
	}
	data.number = 0;
	do_fractol_bonus(&data);
	mlx_key_hook(data.mlx_win, key_events_bonus, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window_bonus, &data);
	mlx_mouse_hook(data.mlx_win, mouse_zoom_bonus, &data);
	mlx_loop(data.mlx_con);
	return (0);
}
