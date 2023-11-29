/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:45:43 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/20 20:43:17 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	destroy(t_fractol *fc)
{
	mlx_destroy_image(fc->mlx, fc->img);
	mlx_destroy_window(fc->mlx, fc->win);
	exit(0);
	return (0);
}

void	even_init(t_fractol *fc)
{
	mlx_hook(fc->win, ON_KEYDOWN, 0, &keyclick, fc);
	mlx_hook(fc->win, ON_DESTROY, 0, &destroy, fc);
	mlx_hook(fc->win, ON_MOUSEDOWN, 0, &mouse_scroll, fc);
	mlx_hook(fc->win, ON_MOUSEMOVE, 0, &mouse_move, fc);
}
