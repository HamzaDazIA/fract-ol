/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/27 20:17:26 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_float(char *str)
{
	int	i_float;
	int	i;

	i = 0;
	i_float = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (i_float)
				return (0);
			i_float = 1;
		}
		else if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *str)
{
	int		i;
	double	rs2;
	double	rs;
	int		div;
	int		sign;

	if (!is_float(str))
		print_usage();
	(1) && (rs = 0.0, rs2 = 0.0, sign = 1, div = 1, i = 0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		rs = rs * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
			(1) && (rs2 = rs2 * 10 + (str[i] - '0'), div *= 10);
		rs += rs2 / div;
	}
	return (rs * sign);
}

int	check_float(int ac, char **av)
{
	int	i;

	i = 2;
	while (i < ac)
	{
		if (ft_atof(av[i]) > 100.0 || ft_atof(av[i]) < -100.0)
		{
			write(2, "Error: try entering a number between real (-2->2) "
				"and imag (-2->2).\n", 68);
			exit(1);
		}
		i++;
	}
	return (1);
}

int parsin(int ac, char **av, t_data *data)
{
	if (check_float(ac, av) == 0)
		return (0);
    if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
    {
		(1) && (data->fractol = 1, data->zoom = 1.0, data->offset.real = 0.0);
        data->offset.imag = 0.0;
        return (1);
    }
    else if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
    {
		(1) && (data->fractol = 2, data->zoom = 0.9);
        data->julia_n.real = ft_atof(av[2]);
        data->julia_n.imag = ft_atof(av[3]);
        return (1);
    }
    else if (ft_strcmp(av[1], "multibrot") == 0 && ac == 2)
    {
        data->fractol = 3;
        data->zoom = 1.0;
        data->offset.real = 0.0;
        data->offset.imag = 0.0;
        return (1);
    }
    return (0);
}
