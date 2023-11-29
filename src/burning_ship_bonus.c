/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:39:20 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/20 20:55:21 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ship(t_fractol *fc, t_img *img, int x, int y)
{
	int		i;
	double	temp;

	i = 0;
	while (++i < fc->mx_iter)
	{
		temp = fc->z.x * fc->z.x - fc->z.y * fc->z.y + fc->c.x;
		fc->z.y = fabs(2. * fc->z.x * fc->z.y + fc->c.y);
		fc->z.x = fabs(temp);
		if (fc->z.x * fc->z.x + fc->z.y * fc->z.y > 4)
			break ;
	}
	if (i == fc->mx_iter)
		pixel_put(img, x, y, 0x00000000);
	else
		pixel_put(img, x, y, get_color(i));
}

void	drawit_bonus(t_fractol *fc, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fc->z = complex(0, 0);
			fc->c.x = coordinate(x, WIDTH, fc->start.x, fc->end.x);
			fc->c.y = coordinate(y, HEIGHT, fc->start.y, fc->end.y);
			ship(fc, img, x, y);
			y++;
		}
		x++;
	}
}
