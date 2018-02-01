/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:55:52 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/25 22:58:14 by ddosso-d         ###   ########.fr       */
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
	--a;
	if (a == 18)
		ft_initc(t / 1000000000000000000 + '0', i);
	else
		ft_initc(t / ft_power(10, a + 1) % 10 + '0', i);
	if (i->a)
		ft_initc('.', i);
	while (--a >= 0)
		ft_initc(t / ft_power(10, a + 1) % 10 + '0', i);
}

static void			ft_e_for_e(char c, int e, t_info *i)
{
	ft_initc(c, i);
	if (e < 0)
	{
		e *= -1;
		ft_initc('-', i);
	}
	else
		ft_initc('+', i);
	ft_initc(e / 10 + '0', i);
	ft_initc(e % 10 + '0', i);
}

void				ft_e(long double n, t_info *i, char c)
{
	int			a;
	long long	t;

	if (i->a == -1)
		i->a = 6;
	a = 0;
	while (n && n * ft_power(10, a) < 1 && n * ft_power(10, a) > -1)
		++a;
	while (n / ft_power(10, a) >= 10 || n / ft_power(10, a) <= -10)
		++a;
	t = ((n < 1.0 && n > -1.0) ? n * ft_power(10, a) : n / ft_power(10, a))
		* ft_power(10, i->a + 1);
	i->d -= (i->a) ? i->a + 6 : 5;
	if (i->c == 0)
		while (--i->d >= 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (--i->d >= 0)
			ft_initc('0', i);
	ft_nbr(t, i->a + 1, ((n < 1.0 && n > -1.0) ? n * ft_power(10, a + 1) :
		n / ft_power(10, a + 1)), i);
	ft_e_for_e(c, (n < 1.0 && n > -1.0) ? -(a - 1) : a - 1, i);
	if (i->c == 2)
		while (--i->d >= 0)
			ft_initc(' ', i);
}
