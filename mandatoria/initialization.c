/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:30:24 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 05:18:35 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_initialization(t_data *data)
{
	data->mlx_con = mlx_init();
	if (!data->mlx_con)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_con, WIDTH, HEIGHT, "fract-ol");
	if (!data->mlx_win)
	{
		return (1);
	}
	data->img = mlx_new_image(data->mlx_con, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_destroy_window(data->mlx_con, data->mlx_win);
		return (1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}
