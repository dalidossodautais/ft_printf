/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:57:13 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 19:57:14 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(unsigned long long n, unsigned long long t, t_info *i,
	const char b)
{
	int		a;

	a = 0;
	if (n || i->a)
		a = 1;
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	while (i->a-- > 0)
		ft_initc('0', i);
	if (a)
		while (t)
		{
			ft_initc(n / t % b + '0', i);
			t /= b;
		}
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
}

void		ft_u(unsigned long long n, t_info *i, const char b)
{
	unsigned long long	t;
	int					a;

	a = 0;
	t = 1;
	while (++a && n / b / t)
		t *= b;
	if (!n && !i->a)
		a = 0;
	if (a < i->a)
		i->d -= i->a;
	else
		i->d -= a;
	if (i->a)
		i->a = (i->a - a) ? i->a - a : -1;
	ft_nbr(n, t, i, b);
}
