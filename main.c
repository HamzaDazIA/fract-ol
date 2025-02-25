/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:03 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/25 22:24:55 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	write(1, "\nUsage:\n", 9);
	write(1, "fractol <fractal_type>\n\n", 25);
	write(1, "Available fractals:\n\n", 22);
	write(1, "🌀 mandelbrot\n", 17);
	write(1, "🌊 julia <real> <imag>\n", 26);
	write(1, "🔥 burning_ship\n\n", 20);
    exit(EXIT_FAILURE);
}


int main(int argc , char **argv)
{
    t_data  data;
    if (HEIGHT <= 0 || HEIGHT > 2500 || WIDTH <= 0 || WIDTH > 2500)
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
    data.end_color = 0xFFCDB2;
    data.start_color = 0xB5828C;
    do_fractol(&data);
    mlx_key_hook(data.mlx_win, key_events, &data);
    mlx_hook(data.mlx_win, 17, 0, close_window, &data);
    mlx_hook(data.mlx_win, 4, 0, mouse_zoom, &data);
    mlx_loop(data.mlx_con);
}
