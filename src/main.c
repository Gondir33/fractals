/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: marvin <marvin@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2022/02/22 13:10:44 by sbendu	#+#	#+#	 */
/*   Updated: 2022/03/09 06:13:22 by marvin	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_vars(t_vars *vars, char **av)
{
	vars->offx = -2;
	vars->offy = -1.4;
	vars->side = 4;
	vars->c.re = 0;
	vars->c.im = 0;
	if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
	{
		vars->flag = 'M';
		vars->offx = -2.5;
	}
	if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		vars->flag = 'J';
		vars->c.re = ft_double(av[2]);
		vars->c.im = ft_double(av[3]);
	}
}

int	destroy_hook(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	exit(0);
	return (0);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free (vars->mlx);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int k, int x, int y, t_vars *vars)
{
	double	movex;
	double	movey;

	movex = (double)(x - (WIDTH / 2)) / 100;
	movey = (double)(y - (HEIGHT / 2)) / 100;
	if (k == 4)
		zoom(vars, '+', movex, movey);
	else if (k == 5)
		zoom(vars, '-', movex, movey);
	make_fractol(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (check_input(ac, av) != 0)
		return (1);
	init_vars(&vars, av);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");
	init_img(&vars);
	make_fractol(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, destroy_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
