/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:54:44 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/27 17:24:43 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int get_color(int i, t_data *data)
{
    double  t;
    int     r;
    int     g;
    int     b;

    if (i == MAX_ITER)
        return (0x000000);
    t = (double)i / MAX_ITER;
    r = (1 - t) * ((data->start_color >> 16) & 0xFF) + t * ((data->end_color >> 16) & 0xFF);
    g = (1 - t) * ((data->start_color >> 8) & 0xFF) + t * ((data->end_color >> 8) & 0xFF);
    b = (1 - t) * (data->start_color & 0xFF) + t * (data->end_color & 0xFF);
    return ((r << 16) | (g << 8) | b);
}

void	draw_mandelbrot(t_data *data)
{
	int				x;
	int				y;
	t_complex		c;
	int				iter;
	unsigned int	*pixel;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = pixel_to_complex(x, y, data);
			iter = mandelbrot(c);
			data->color = get_color(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	draw_multibrot(t_data *data)
{
	int				x;
	int				y;
	t_complex		c;
	int				iter;
	unsigned int	*pixel;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = pixel_to_complex(x, y, data);
			iter = multibrot(c);
			data->color = get_color(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	draw_julia(t_data *data)
{
	int				x;
	int				y;
	t_complex		z;
	int				iter;
	unsigned int	*pixel;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = pixel_to_complex(x, y, data);
			iter = julia(z, data->julia_n);
			data->color = get_color(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	do_fractol(t_data *data)
{
	if (data->fractol == MANDELBROT)
		draw_mandelbrot(data);
	else if (data->fractol == JULIA)
		draw_julia(data);
	else if (data->fractol == MULTIBROT)
		draw_multibrot(data);
}
