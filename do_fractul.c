/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:54:44 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/26 00:23:01 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int i, t_data *data)
{
	int	result;

	if (i == MAX_ITER)
		return (0x000000);
	result = (i * (data->end_color - data->start_color) / MAX_ITER)
		+ data->start_color;
	return (result);
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
