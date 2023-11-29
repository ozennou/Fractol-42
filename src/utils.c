/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:56:55 by mozennou          #+#    #+#             */
/*   Updated: 2023/11/19 21:46:49 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_digit(char *s)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (s[i] && (s[i] == ' ' || func(s[i]))) 
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			return (0);
		if (s[i] == '.')
		{
			if (p == 0)
				p = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	func0(const char	*s, int i, int neg)
{
	unsigned long long	res;
	int					digitnbr;

	res = 0;
	digitnbr = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		digitnbr++;
		if (digitnbr == 20)
		{
			if (neg == -1)
				return (0);
			else
				return (-1);
		}
		res = (res * 10) + (s[i++] - '0');
	}
	if (res > __LONG_MAX__) 
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	return (((int) res) * neg);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || func(s[i]))) 
		i++;
	if (s[i] == '+' || s[i] == '-') 
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] && s[i] == '0')
		i++;
	return (func0(s, i, neg));
}

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*pp;

	i = 0;
	p = (unsigned char *)a;
	pp = (unsigned char *)b;
	while (i < n && (p[i] || pp[i]))
	{
		if (p[i] != pp[i])
			return (p[i] - pp[i]);
		i++;
	}
	return (0);
}
