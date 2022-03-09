/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:08:47 by sbendu            #+#    #+#             */
/*   Updated: 2022/03/09 15:55:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	zoom(t_vars *vars, char k, double x, double y)
{
	int	way;

	way = 1;
	if (k == '-' && vars->side >= 5)
		return ;
	if (k == '-')
		way = -1;
	vars->side -= way * (0.04 * vars->side);
	vars->offx += way * (0.02 * vars->side + (x * 0.01 * vars->side));
	vars->offy += way * (0.02 * vars->side + (y * 0.01 * vars->side));
}

double	ft_con(char *s, int i, double d)
{
	double	iter;

	iter = 10;
	while (s[i] >= '0' && s[i] < '9')
	{
		d = d + ((double)(s[i] - 48) / iter);
		iter *= 10;
		i++;
	}
	return (d);
}

double	ft_double(char *s)
{
	double	d;
	double	flag;
	int		i;

	i = -1;
	d = 0;
	flag = 1;
	if (s[++i] == '-')
		flag = -1;
	i++;
	while (s[i] >= '0' && s[i] < '9')
	{
		d = (double)(s[i] - 48) + d * 10;
		i++;
	}
	if (s[i++] != '.')
		return (d * flag);
	return (flag * ft_con(s, i, d));
}

void	init_img(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = (int *)mlx_get_data_addr(vars->img,
			&vars->bpp, &vars->ll, &vars->end);
}
