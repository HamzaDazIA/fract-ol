/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:58:54 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/19 12:01:30 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define Mandelbrot 1
# define Julia 2 

typedef struct	s_data {
    void    *mlx_conaction;
    void    *win_mlx;
	int		name_fractol;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct n_complex
{
    double  real;

    double  i;
    
}      t_complex ;


int idef_mlx(t_data *mlx);

    

#endif