/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:03 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/22 05:59:32 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	write(1, "\n\033[1;34mUsage:\n", 15);
	write(1, "\033[1;34m./fractol <fractal_type>\n\n", 33);
	write(1, "\033[1;32mAvailable fractals:\n\n", 28);
	write(1, "\033[1;33m  🌀 mandelbrot\n", 25);
	write(1, "\033[1;35m  🌊 julia <real> <imag>\n", 34);
	write(1, "\033[1;36m  🔥 burning_ship\n\n", 28);
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
    do_fractol(&data);
    
    mlx_loop(data.mlx_con);
}