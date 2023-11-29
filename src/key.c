/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:31:15 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/19 21:10:18 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keyclick2(int key, t_fractol *fc)
{
	if (key == KEY_DOWN)
	{
		fc->start.y += fabs(fc->end.y - fc->start.y) * 0.05;
		fc->end.y += fabs(fc->end.y - fc->start.y) * 0.05;
	}
	else if (key == KEY_UP)
	{
		fc->start.y -= fabs(fc->end.y - fc->start.y) * 0.05;
		fc->end.y -= fabs(fc->end.y - fc->start.y) * 0.05;
	}
	else if (key == KEY_LEFT)
	{
		fc->start.x -= fabs(fc->end.x - fc->start.x) * 0.05;
		fc->end.x -= fabs(fc->end.x - fc->start.x) * 0.05;
	}
	else if (key == KEY_RIGHT)
	{
		fc->start.x += fabs(fc->end.x - fc->start.x) * 0.05;
		fc->end.x += fabs(fc->end.x - fc->start.x) * 0.05;
	}
	else
		return (0);
	return (1);
}

int	keyclick(int key, void *ptr)
{
	t_fractol	*fc ;

	fc = (t_fractol *)ptr;
	if (key == KEY_ESC)
		destroy(fc);
	else if (key == KEY_SPACE)
	{
		if (fc->space == 0)
			fc->space = 1;
		else
			fc->space = 0;
	}
	else if (key == KEY_R)
	{
		fc->start = complex(-WIDTH / 300, -HEIGHT / 300);
		fc->end = complex(WIDTH / 300, HEIGHT / 300);
		fc->mx_iter = 100;
	}
	else if (keyclick2(key, fc) == 0)
		return (0);
	render(fc);
	return (0);
}
