/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:53:08 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/23 00:43:39 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int key_events(int key, t_data *data)
{
    if (key == ESC)
    {
        mlx_destroy_image(data->mlx_con, data->img);
        mlx_destroy_window(data->mlx_con, data->mlx_win);
        return  (0);
    }
    return (0);
}

int mouse_hook(int button, int x,int y, t_data *data)
{
    if (button == 4)
    {
        data->zoom -= 0.04;
    }
    else if (button == 5)
    {
        data->zoom += 0.05; 
    }
    do_fractol(data);
    return 0;
}