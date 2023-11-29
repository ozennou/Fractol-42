/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:38:27 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/20 20:53:34 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->bf + (y * data->ln_b + x * (data->pxl_b / 8));
	*(unsigned int *) dst = color;
}

void	mandel_julia(t_fractol *fc, t_img *img, int x, int y)
{
	int		i;
	double	temp;

	i = 0;
	while (++i < fc->mx_iter)
	{
		temp = fc->z.x * fc->z.x - fc->z.y * fc->z.y + fc->c.x;
		fc->z.y = 2 * fc->z.x * fc->z.y + fc->c.y;
		fc->z.x = temp;
		if (fc->z.x * fc->z.x + fc->z.y * fc->z.y > 4)
			break ;
	}
	if (i == fc->mx_iter)
		pixel_put(img, x, y, 0x00000000);
	else
		pixel_put(img, x, y, get_color(i));
}

void	drawit_mandel(t_fractol *fc, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fc->z.x = 0;
			fc->z.y = 0;
			fc->c.x = coordinate(x, WIDTH, fc->start.x, fc->end.x);
			fc->c.y = coordinate(y, HEIGHT, fc->start.y, fc->end.y);
			mandel_julia(fc, img, x, y);
			y++;
		}
		x++;
	}
}

void	drawit_julia(t_fractol *fc, t_img *img)
{
	int	x;
	int	y;

	fc->c.x = fc->julia.x;
	fc->c.y = fc->julia.y;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fc->z.x = coordinate(x, WIDTH, fc->start.x, fc->end.x);
			fc->z.y = coordinate(y, HEIGHT, fc->start.y, fc->end.y);
			mandel_julia(fc, img, x, y);
			y++;
		}
		x++;
	}
}
