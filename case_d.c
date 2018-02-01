/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 05:11:44 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 05:11:45 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(long long n, long long t, t_info *i, int a)
{
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (n < 0)
		ft_initc('-', i);
	else if (i->e)
		ft_initc(i->e, i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	while (a++ < i->a)
		ft_initc('0', i);
	if (n < -9223372036854775807)
		ft_inits("9223372036854775808", i);
	else if ((n || i->a) && (n >= 0 || (n *= -1)))
		while (t)
		{
			ft_initc(n / t % 10 + '0', i);
			t /= 10;
		}
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
}

void		ft_d(long long n, t_info *i)
{
	long long	t;
	char		a;

	a = 0;
	t = 1;
	while (++a && n / 10 / t)
		t *= 10;
	if (!n && !i->a)
		a = 0;
	if (a < i->a)
		i->d -= i->a;
	else
		i->d -= a;
	if (i->a)
		i->a = (i->a - a) ? i->a - a : -1;
	if (n < 0 || i->e)
		i->d--;
	ft_nbr(n, t, i, (a = 0));
}
