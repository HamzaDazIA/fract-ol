/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:18:02 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/26 00:26:52 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;
	double		tmp;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}

int	julia(t_complex z0, t_complex c_julia)
{
	int			iter;
	double		tmp;

	iter = 0;
	while (z0.real * z0.real + z0.imag * z0.imag <= 4 && iter < MAX_ITER)
	{
		tmp = z0.real * z0.real - z0.imag * z0.imag + c_julia.real;
		z0.imag = 2 * z0.real * z0.imag + c_julia.imag;
		z0.real = tmp;
		iter++;
	}
	return (iter);
}

int	multibrot(t_complex c)
{
	int			i;
	double		tmp;
	t_complex	z;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && i < MAX_ITER)
	{
		tmp = (z.real * z.real * z.real) - (3 * z.real * z.imag * z.imag)
			+ c.real;
		z.imag = (3 * z.real * z.real * z.imag) - (z.imag * z.imag * z.imag)
			+ c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}
