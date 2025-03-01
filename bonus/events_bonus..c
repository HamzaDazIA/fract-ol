/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus..c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:53:08 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 04:43:12 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_con, data->img);
	mlx_destroy_window(data->mlx_con, data->mlx_win);
	exit(0);
}

int	key_events(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_con, data->img);
		mlx_destroy_window(data->mlx_con, data->mlx_win);
		exit(0);
	}
	else if (key == 49)
		data->number += 3;
	else if (key == 125)
		data->offset.imag += 0.1 * data->zoom;
	else if (key == 126)
		data->offset.imag -= 0.1 * data->zoom;
	else if (key == 123)
		data->offset.real -= 0.1 * data->zoom;
	else if (key == 124)
		data->offset.real += 0.1 * data->zoom;
	do_fractol(data);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_scale;

	mouse_x = (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom
		+ data->offset.real;
	mouse_y = (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom
		+ data->offset.imag;
	if (button == 4)
		zoom_scale = 0.9;
	else if (button == 5)
		zoom_scale = 1.1;
	else
		return (0);
	data->zoom *= zoom_scale;
	data->offset.real = mouse_x - (x * (N_MAX - N_MIN) / WIDTH + N_MIN)
		* data->zoom;
	data->offset.imag = mouse_y - (y * (N_MAX - N_MIN) / HEIGHT + N_MIN)
		* data->zoom;
	do_fractol(data);
	return (0);
}
