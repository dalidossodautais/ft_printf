/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sput.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:53:57 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/11 00:53:59 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putdbl(const char c, struct s_info *i)
{
	if (c == 'e')
		(i->f == 7) ? ft_e(va_arg(i->u, long double), i, c) :
			ft_e(ft_to_d(va_arg(i->u, double)), i, c);
	else if (c == 'f' || c == 'F')
		(i->f == 7) ? ft_f(va_arg(i->u, long double), i) :
			ft_f(ft_to_d(va_arg(i->u, double)), i);
	else if (c == 'E')
		(i->f == 7) ? ft_e(va_arg(i->u, long double), i, c) :
			ft_e(ft_to_d(va_arg(i->u, double)), i, c);
}

static void	ft_putcase(const char c, struct s_info *i)
{
	if (c == 'b')
		ft_put_u(2, i);
	else if (c == 'd' || c == 'i')
		ft_put_d(i);
	else if (c == 'o')
		ft_put_o(i);
	else if (c == 'u')
		ft_put_u(10, i);
	else if (c == 'x' || c == 'X')
		ft_put_x(c - 33, i);
	else if (c == 'D')
		ft_d(va_arg(i->u, long), i);
	else if (c == 'O')
		ft_o(va_arg(i->u, unsigned long), i);
	else if (c == 'p' && (i->b = 1))
		ft_p(va_arg(i->u, unsigned long), i);
	else if (c == 'U')
		ft_u(va_arg(i->u, unsigned long), i, 10);
}

static int	ft_putstr(const char c, struct s_info *i)
{
	if (c == 'C' || (c == 'c' && i->f == 4))
	{
		if (!ft_lc(va_arg(i->u, const int), i))
			return (0);
	}
	else if (c == 'S' || (c == 's' && i->f == 4))
	{
		if (!ft_ls(va_arg(i->u, int *), i))
			return (0);
	}
	else if (c == 'c')
		ft_c(va_arg(i->u, const int), i);
	else if (c == 's')
		ft_s(va_arg(i->u, char *), i);
	else if (c == 'v' && i->f == 0)
		ft_s(ft_non_printable(va_arg(i->u, const int)), i);
	return (1);
}

int			ft_sput(const char c, struct s_info *i)
{
	if (c == 'b' || c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'p' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		ft_putcase(c, i);
	else if (c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' ||
		c == 'G' || c == 'a' || c == 'A')
		ft_putdbl(c, i);
	else if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'v')
		return (ft_putstr(c, i));
	else if (c == 'n')
		*va_arg(i->u, int *) = i->y;
	else if (c == 'm')
		ft_m(va_arg(i->u, const char *), i);
	else
		ft_c(c, i);
	return (0);
}
