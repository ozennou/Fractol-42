/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:12:29 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/21 11:41:46 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render(t_fractol *fc)
{
	t_img	img;

	img.img = fc->img;
	img.bf = mlx_get_data_addr(img.img, &img.pxl_b, &img.ln_b, &img.endian);
	if (fc->type == 1)
		drawit_mandel(fc, &img);
	else if (fc->type == 2)
		drawit_julia(fc, &img);
	else if (fc->type == 3)
		drawit_bonus(fc, &img);
	mlx_clear_window(fc->mlx, fc->win);
	mlx_put_image_to_window(fc->mlx, fc->win, fc->img, 0, 0);
	even_init(fc);
}

t_cmplx	complex(double x, double y)
{
	t_cmplx	c;

	c.x = x;
	c.y = y;
	return (c);
}

double	coordinate(int pos, int len, double min, double max)
{
	double	dis;
	double	res;
	double	p;

	dis = fabs(max - min);
	p = (double)pos / (double)len;
	res = min + (p * dis);
	return (res);
}

void	ft_error(int i)
{
	if (!i)
	{
		ft_putstr_fd("Usage:  ./fractol Mandelbrot\n", 1);
		ft_putstr_fd("\t./fractol Julia cx cy (Values in the range of the ", 1);
		ft_putstr_fd("screen (Default [0 ; 599])\n\t./fractol Burning_ship\n", 1);
	}
	else
		ft_putstr_fd("MLX : Error", 2);
	exit(i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}
