/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:21 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/27 20:26:46 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# ifndef N_MAX
#  define N_MAX 2.0
# endif

# ifndef N_MIN
#  define N_MIN -2.0
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	void			*mlx_con;
	void			*mlx_win;
	int				fractol;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_complex		offset;
	double			zoom;
	t_complex		julia_n;
	int			number;
	unsigned int	color;
}				t_data;


void		print_usage(void);
int			ft_strcmp(char *s1, char *s2);
int			parsin(int ac, char **av, t_data *data);
int			mlx_conialization(t_data *data);
void		do_fractol(t_data *data);
int			key_events(int key, t_data *data);
int			mouse_zoom(int button, int x, int y, t_data *data);
t_complex	pixel_to_complex(int x, int y, t_data *data);
int			close_window(t_data *data);
int			mandelbrot(t_complex c);
int			julia(t_complex z0, t_complex c_julia);
int			multibrot(t_complex c);

#endif