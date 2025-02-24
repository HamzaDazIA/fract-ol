/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:21 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/24 11:23:38 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
#define FRACTOL

#define WIDTH 1080
#define HEIGHT  1080 

#define MANDELBROT 1
#define Julia    2
#define MULTIBROT	3

#define N_MAX 2.0
#define N_MIN -2.0
#define MAX_ITER 100
# define ESC 53

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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
	t_complex	julia_n;
	
}				t_data;

void	print_usage(void);
int ft_strcmp(char *s1, char *s2);
int parsin(int ac, char **av, t_data  *data);
int  mlx_conialization(t_data *data);
void    do_fractol(t_data *data);
int key_events(int key, t_data *data);
int mouse_hook(int button, int x,int y, t_data *data);
t_complex pixel_to_complex(int x, int y, t_data *data);
double ft_atof(char *str);
int	close_window(t_data *data);
void    draw_multibrot(t_data  *data);
unsigned int get_color(int iter);

#endif
