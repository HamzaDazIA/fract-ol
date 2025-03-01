/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:53:08 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 05:11:14 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	do_fractol(data);
	return (0);
}
