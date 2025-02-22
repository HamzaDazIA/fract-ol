/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:21 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/22 06:05:17 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
#define FRACTOL

#define WIDTH 800
#define HEIGHT  800 

#define MANDELBROT 1
#define Julia    2
#define N_MAX 2.0
#define N_MIN -2.0
#define MAX_ITER 100

#include <unistd.h>
#include <mlx.h>


typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;


typedef struct	s_data {
    void    *mlx_con;
    void    *mlx_win;
    int     fractol;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	t_complex	offset;
}				t_data;

int ft_strcmp(char *s1, char *s2);
int parsin(int ac, char **av, t_data  *data);
int  mlx_conialization(t_data *data);
void    do_fractol(t_data *data);



#endif
