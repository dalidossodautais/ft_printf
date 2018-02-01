/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:12:52 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/16 19:12:53 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(unsigned long long n, unsigned long long t, t_info *i)
{
	int		a;

	a = 0;
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (i->b)
		ft_initc('0', i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	while (a++ < i->a)
		ft_initc('0', i);
	if (n || (i->a && !i->b))
		while (t)
		{
			ft_initc(n / t % 8 + '0', i);
			t /= 8;
		}
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
}

void		ft_o(unsigned long long n, t_info *i)
{
	unsigned long long	t;
	char				a;

	a = 0;
	t = 1;
	while (++a && n / 8 / t)
		t *= 8;
	if (!n && !i->a)
		a = 0;
	if (a < i->a)
		i->d -= i->a;
	else
		i->d -= a;
	if (i->a)
		i->a = (i->a - a) ? i->a - a : -1;
	if (i->b)
	{
		i->a--;
		i->d--;
	}
	ft_nbr(n, t, i);
}
