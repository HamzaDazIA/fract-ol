/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:15:26 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/19 11:59:00 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int idef_mlx(t_data *data)
{
    data->mlx_conaction = mlx_init();
    if ( data->mlx_conaction == NULL)
        return (0);
    data->win_mlx = mlx_new_window(data->mlx_conaction, WIDTH, HEIGHT, "fract'ol");
    if  (data->win_mlx)
        return (0);
    data->img = mlx_new_image(data->mlx_conaction, WIDTH, HEIGHT);
    if (data->img == NULL)
    {
        mlx_destroy_window(data->mlx_conaction, data->win_mlx);
        return (0);
    }
    data->addr = mlx_get_data_addr(data->img, data->bits_per_pixel, data->line_length, data->endian);
    return (1);
}