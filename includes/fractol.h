/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:07:26 by sbendu            #+#    #+#             */
/*   Updated: 2022/03/11 13:13:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf.h"
# define WIDTH	800
# define HEIGHT	800

typedef struct s_complex
{
	double	re;
	double	im;
}		t_complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bpp;
	int			ll;
	int			end;
	t_complex	c;
	double		offx;
	double		offy;
	double		side;
	char		flag;
}		t_vars;

void	make_fractol(t_vars *vars);
double	ft_double(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	zoom(t_vars *vars, char k, double x, double y);
void	init_img(t_vars *vars);
int		check_input(int ac, char **av);

#endif