/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:08:10 by sbendu            #+#    #+#             */
/*   Updated: 2022/03/11 13:11:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	color(int i)
{
	int		r;
	int		g;
	int		b;

	r = sin(0.08 * i + 2) * 128 + 127;
	g = sin(0.08 * i + 0) * 128 + 127;
	b = sin(0.08 * i + 4) * 128 + 127;
	return (r << 16 | g << 8 | b);
}

void	make_mandelbrot(t_complex c, int x, int y, t_vars *vars)
{
	t_complex	zsqr;
	t_complex	z;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	zsqr.re = z.re * z.re;
	zsqr.im = z.im * z.im;
	while ((zsqr.re + zsqr.im < 4) && (i < 256))
	{
		z.im = 2 * z.im * z.re + c.im;
		z.re = zsqr.re - zsqr.im + c.re;
		zsqr.re = z.re * z.re;
		zsqr.im = z.im * z.im;
		i++;
	}
	if (i < 256)
		vars->addr[y * WIDTH + x] = color(i);
	else
		vars->addr[y * WIDTH + x] = 0x00000000;
}

void	make_julia(t_complex z, int x, int y, t_vars *vars)
{
	t_complex	zsqr;
	int			i;

	i = 0;
	zsqr.re = z.re * z.re;
	zsqr.im = z.im * z.im;
	while ((zsqr.re + zsqr.im < 4) && (i < 256))
	{
		z.im = 2 * z.im * z.re + vars->c.im;
		z.re = zsqr.re - zsqr.im + vars->c.re;
		zsqr.re = z.re * z.re;
		zsqr.im = z.im * z.im;
		i++;
	}
	if (i < 256)
		vars->addr[y * WIDTH + x] = color(i);
	else
		vars->addr[y * WIDTH + x] = 0x00000000;
}

void	make_fractol(t_vars *vars)
{
	t_complex	c;
	int			x;
	int			y;
	double		ratio;

	y = -1;
	ratio = vars->side / WIDTH;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			c.re = x * ratio + vars->offx;
			c.im = y * ratio + vars->offy;
			if (vars->flag == 'M')
				make_mandelbrot(c, x, y, vars);
			if (vars->flag == 'J')
				make_julia(c, x, y, vars);
		}
	}
}

int	check_input(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Mandelbrot: %s\nJulia:%s and 2 param like that\n%s %s\n",
			"Mandelbrot", "Julia", "-0.7", " 0.27015");
		return (1);
	}
	if ((ft_strncmp(av[1], "Mandelbrot", 11) != 0)
		&& (!(ft_strncmp(av[1], "Julia", 6) == 0 && ac > 3)))
	{
		ft_printf("Mandelbrot: %s\nJulia:%s and 2 param like that\n%s %s\n",
			"Mandelbrot", "Julia", "-0.7", " 0.27015");
		return (1);
	}
	return (0);
}
