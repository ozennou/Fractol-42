/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:08:31 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/19 22:31:45 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	func(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

double	ft_atoi2(char *s)
{
	double	res;
	int		p2;
	int		l;
	int		neg;
	char	*c;

	neg = 1;
	while (*s && func(*s))
		s++;
	if (*s && (*s == '-' || *s == '+'))
	{
		if (*s == '-')
			neg = -neg;
		s++;
	}
	res = (double)ft_atoi(s);
	c = s;
	while (*c && *c != '.')
		c++;
	if ((*c) == '\0')
		return (res * neg);
	p2 = ft_atoi(++c);
	l = ft_strlen(c);
	res = res + (double)(p2 / pow(10, l));
	return (res * neg);
}
