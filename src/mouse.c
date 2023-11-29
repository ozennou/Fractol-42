/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:54 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/19 22:25:00 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	zoom_in(t_fractol *fc, t_cmplx mouse)
{
	double	z_factor;

	z_factor = 0.5;
	fc->start.x = (fc->start.x - mouse.x) * z_factor + mouse.x;
	fc->start.y = (fc->start.y - mouse.y) * z_factor + mouse.y;
	fc->end.x = (fc->end.x - mouse.x) * z_factor + mouse.x;
	fc->end.y = (fc->end.y - mouse.y) * z_factor + mouse.y;
	fc->mx_iter += 7;
	render(fc);
}

void	zoom_out(t_fractol *fc, t_cmplx mouse)
{
	double	z_factor;

	z_factor = 2.0;
	fc->start.x = (fc->start.x - mouse.x) * z_factor + mouse.x;
	fc->start.y = (fc->start.y - mouse.y) * z_factor + mouse.y;
	fc->end.x = (fc->end.x - mouse.x) * z_factor + mouse.x;
	fc->end.y = (fc->end.y - mouse.y) * z_factor + mouse.y;
	if (fc->mx_iter > 100)
		fc->mx_iter -= 7;
	render(fc);
}

int	mouse_scroll(int key, int x, int y, void *ptr)
{
	t_fractol	*fc;
	t_cmplx		mouse;

	fc = (t_fractol *)ptr;
	mouse.x = coordinate(x, WIDTH, fc->start.x, fc->end.x);
	mouse.y = coordinate(y, HEIGHT, fc->start.y, fc->end.y);
	if (key == MOUSE_SCROLL_UP && fc->mx_iter < 450)
		zoom_in(fc, mouse);
	else if (key == MOUSE_SCROLL_DOWN)
		zoom_out(fc, mouse);
	if (fabs(fc->start.x - fc->end.x) > 4 && fabs(fc->start.y - fc->end.y) > 4)
		fc->mx_iter = 100;
	return (0);
}

int	mouse_move(int x, int y, void *ptr)
{
	t_fractol	*fc;

	fc = (t_fractol *)ptr;
	if (fc->type == 2 && fc->space == 1)
	{
		fc->julia.x = coordinate(x, WIDTH, fc->start.x, fc->end.x);
		fc->julia.y = coordinate(y, HEIGHT, fc->start.y, fc->end.y);
		render(fc);
	}
	return (0);
}
