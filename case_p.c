/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 06:57:59 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/24 06:58:03 by ddosso-d         ###   ########.fr       */
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
	ft_inits("0x", i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	while (a++ < i->a)
		ft_initc('0', i);
	if (n || i->a)
		while (t)
		{
			(n / t % 16 < 10) ? ft_initc(n / t % 16 + '0', i) :
				ft_initc(n / t % 16 + 87, i);
			t /= 16;
		}
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
}

void		ft_p(unsigned long long n, t_info *i)
{
	unsigned long long	t;
	int					a;

	a = 0;
	t = 1;
	while (++a && n / 16 / t)
		t *= 16;
	if (!n && !i->a)
		a = 0;
	if (a < i->a)
		i->d -= i->a;
	else
		i->d -= a;
	if (i->a)
		i->a = (i->a - a) ? i->a - a : -1;
	i->d -= 2;
	ft_nbr(n, t, i);
}
