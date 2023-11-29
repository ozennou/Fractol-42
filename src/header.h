/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:59:21 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/20 12:05:40 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "defines.h"

// line_bytes : number of bytes in each row (line)
// pixel_bits : bits used to represent each pixel
// endian : set of the data 0:little-endian 1:big endian
typedef struct s_cmplx
{
	double	x;
	double	y;
}	t_cmplx;

typedef struct s_fractol
{
	int		space;
	int		type;
	int		mx_iter;
	t_cmplx	c;
	t_cmplx	z;
	t_cmplx	julia;
	t_cmplx	start;
	t_cmplx	end;
	void	*img;
	void	*mlx;
	void	*win;
	double	zoom;
}	t_fractol;

typedef struct s_img
{
	void	*img;
	char	*bf;
	int		pxl_b;
	int		ln_b;
	int		endian;
}	t_img;

void			ft_error(int i);
void			set_fractol(t_fractol *fc, int l);
void			drawit_mandel(t_fractol *fc, t_img *img);
void			drawit_julia(t_fractol *fc, t_img *img);
int				ft_digit(char *s);
t_cmplx			complex(double x, double y);
void			even_init(t_fractol *fc);
int				mouse_scroll(int key, int x, int y, void *ptr);
double			coordinate(int pos, int len, double min, double max);
int				keyclick(int key, void *ptr);
void			render(t_fractol *fc);
int				destroy(t_fractol *fc);
int				mouse_move(int x, int y, void *ptr);
void			drawit_bonus(t_fractol *fc, t_img *img);
unsigned int	get_color(int i);
void			pixel_put(t_img *data, int x, int y, int color);
unsigned int	get_color(int i);
int				ft_atoi(const char *s);
int				ft_strncmp(const char *a, const char *b, size_t n);
void			ft_putstr_fd(char *s, int fd);
int				func(char c);
double			ft_atoi2(char *s);
#endif
