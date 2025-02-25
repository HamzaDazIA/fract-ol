/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:53:08 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/25 11:32:23 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int key_events(int key, t_data *data)
{
    if (key == ESC)
    {
        mlx_destroy_window(data->mlx_con, data->mlx_win);
        exit(0);
    }
	else if (key == 49)
	{
		data->start_color = data->start_color * 3;
		data->end_color = data->end_color * 5;
		do_fractol(data);
	}
    return (0);
}


int	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_scale;

	mouse_x = (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom + data->offset.real;
	mouse_y = (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom + data->offset.imag;
	if (button == 4)
		zoom_scale = 0.9;
	else if (button == 5)
		zoom_scale = 1.1;
	else
		return (0);
	data->zoom *= zoom_scale;
	data->offset.real = mouse_x - (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom;
	data->offset.imag = mouse_y - (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom;
    do_fractol(data);
    return 0;
}