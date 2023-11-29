/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:04:49 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/20 20:57:26 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_fractol(t_fractol *fc, int l)
{
	fc->mlx = mlx_init();
	if (!fc->mlx)
		ft_error(1);
	fc->win = mlx_new_window(fc->mlx, WIDTH, HEIGHT, "Fract-ol");
	fc->img = mlx_new_image(fc->mlx, WIDTH, HEIGHT); 
	fc->space = 0;
	fc->type = l;
	fc->start = complex(-WIDTH / 300, -HEIGHT / 300);
	fc->end = complex(WIDTH / 300, HEIGHT / 300);
	fc->mx_iter = 100;
	fc->zoom = 1.0;
}

int	offered(char **av, char ac)
{
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 11))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 6))
	{
		if (ft_digit(av[2]) && ft_digit(av[3]))
			return (2);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "Burning_ship", 13))
		return (3);
	return (0);
}

int	main(int ac, char **av)
{
	int			l;
	t_fractol	frac;

	if (ac == 2 || ac == 4)
	{
		l = offered(av, ac);
		if (l == 0)
			ft_error(0);
		set_fractol(&frac, l);
		if (frac.type == 2)
			frac.julia = complex(ft_atoi2(av[2]), -ft_atoi2(av[3]));
		if (frac.type == 2 && frac.julia.x == 0)
			frac.julia.y = -frac.julia.y;
		render(&frac);
		mlx_loop(frac.mlx);
	}
	else
		ft_error(0);
	return (0);
}
