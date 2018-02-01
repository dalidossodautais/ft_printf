/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 05:29:52 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/26 05:29:55 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_power(int n, int p)
{
	long long t;

	t = 1;
	if (p > 0)
		while (p--)
			t *= n;
	if (p < 0)
		while (p++)
			t /= n;
	return (t);
}

static void			ft_nbr(long long t, long long a, int b, t_info *i)
{
	if (t < 0)
	{
		ft_initc('-', i);
		t *= -1;
	}
	if (b % 10 >= 5)
		t += 1;
	if (a == 19 && --a)
		ft_initc(t / 1000000000000000000 + '0', i);
	while (--a >= 0)
	{
		ft_initc(t / ft_power(10, a + 1) % 10 + '0', i);
		if (a == i->a)
			ft_initc('.', i);
	}
}

void				ft_f(long double n, t_info *i)
{
	int			a;
	long long	t;

	if (i->a == -1)
		i->a = 6;
	t = n * ft_power(10, i->a + 1);
	a = 1;
	while (n / ft_power(10, a) >= 10 || n / ft_power(10, a) <= -10)
		++a;
	i->d -= (i->a) ? a + i->a + 1 : a;
	if (i->c == 0)
		while (--i->d >= 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (--i->d >= 0)
			ft_initc('0', i);
	ft_nbr(t, a + i->a, n * ft_power(10, i->a + 2) * ((n < 0) ? -1 : 1), i);
	if (i->c == 2)
		while (--i->d >= 0)
			ft_initc(' ', i);
}
