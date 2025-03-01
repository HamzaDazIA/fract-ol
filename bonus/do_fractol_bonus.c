/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractul_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:54:44 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 05:59:33 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

unsigned int	get_color_bonus(int i, t_data *data)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (i == MAX_ITER)
		return (0x000000);
	red = (i * (5 + data->number)) % 256;
	green = (i * (10 + data->number)) % 256;
	blue = (i * (20 + data->number)) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	draw_mandelbrot_bonus(t_data *data)
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
			c = pixel_to_complex_bonus(x, y, data);
			iter = mandelbrot_bonus(c);
			data->color = get_color_bonus(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	draw_multibrot_bonus(t_data *data)
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
			c = pixel_to_complex_bonus(x, y, data);
			iter = multibrot_bonus(c);
			data->color = get_color_bonus(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	draw_julia_bonus(t_data *data)
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
			z = pixel_to_complex_bonus(x, y, data);
			iter = julia_bonus(z, data->julia_n);
			data->color = get_color_bonus(iter, data);
			pixel = (unsigned int *)(data->addr
					+ (y * data->line_length)
					+ (x * (data->bits_per_pixel / 8)));
			*pixel = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void	do_fractol_bonus(t_data *data)
{
	if (data->fractol == 1)
		draw_mandelbrot_bonus(data);
	else if (data->fractol == 2)
		draw_julia_bonus(data);
	else if (data->fractol == 3)
		draw_multibrot_bonus(data);
}
