/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:04:45 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/21 11:44:41 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	color_hue2(double *r, double *g, double *b, double hue)
{
	double	x;

	x = (1 - fabs(fmod(hue, 2.0) - 1));
	if (hue < 4.0)
	{
		*r = 0; 
		*g = x; 
		*b = 1;
	}
	else if (hue < 5.0)
	{
		*r = x; 
		*g = 0; 
		*b = 1;
	}
	else if (hue < 6.0)
	{
		*r = 1; 
		*g = 0; 
		*b = x;
	}
}

void	color_hue(double *r, double *g, double *b, double hue)
{
	double	x;

	x = (1 - fabs(fmod(hue, 2.0) - 1));
	if (hue < 1.0)
	{
		*r = 1; 
		*g = x; 
		*b = 0;
	}
	else if (hue < 2.0)
	{
		*r = x; 
		*g = 1; 
		*b = 0;
	}
	else if (hue < 3.0)
	{
		*r = 0; 
		*g = 1; 
		*b = x;
	}
	else 
		color_hue2(r, g, b, hue);
}

unsigned int	get_color(int i)
{
	double	hue;
	double	r;
	double	g;
	double	b;

	hue = fmod(i * 0.25, 6.0);
	color_hue(&r, &g, &b, hue);
	return (((int)(255 * r) << 16) + ((int)(255 * g) << 8) + (int)(255 * b));
}
