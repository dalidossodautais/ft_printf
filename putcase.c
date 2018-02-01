/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:18:33 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/23 18:48:49 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_d(struct s_info *i)
{
	if (i->f == 1)
		ft_d(ft_to_hh(va_arg(i->u, int)), i);
	else if (i->f == 2)
		ft_d(ft_to_h(va_arg(i->u, int)), i);
	else if (i->f == 3)
		ft_d(va_arg(i->u, long long), i);
	else if (i->f == 4)
		ft_d(ft_to_l(va_arg(i->u, long)), i);
	else if (i->f == 5)
		ft_d(ft_to_j(va_arg(i->u, intmax_t)), i);
	else if (i->f == 6)
		ft_d(ft_to_z(va_arg(i->u, size_t)), i);
	else
		ft_d(ft_to_i(va_arg(i->u, int)), i);
}

void	ft_put_o(struct s_info *i)
{
	if (i->f == 1)
		ft_o(ft_to_uhh(va_arg(i->u, unsigned int)), i);
	else if (i->f == 2)
		ft_o(ft_to_uh(va_arg(i->u, unsigned int)), i);
	else if (i->f == 3)
		ft_o(va_arg(i->u, unsigned long long), i);
	else if (i->f == 4)
		ft_o(ft_to_ul(va_arg(i->u, unsigned long)), i);
	else if (i->f == 5)
		ft_o(ft_to_uj(va_arg(i->u, uintmax_t)), i);
	else if (i->f == 6)
		ft_o(ft_to_uz(va_arg(i->u, ssize_t)), i);
	else
		ft_o(ft_to_ui(va_arg(i->u, unsigned int)), i);
}

void	ft_put_u(const char b, struct s_info *i)
{
	if (i->f == 1)
		ft_u(ft_to_uhh(va_arg(i->u, unsigned int)), i, b);
	else if (i->f == 2)
		ft_u(ft_to_uh(va_arg(i->u, unsigned int)), i, b);
	else if (i->f == 3)
		ft_u(va_arg(i->u, unsigned long long), i, b);
	else if (i->f == 4)
		ft_u(ft_to_ul(va_arg(i->u, unsigned long)), i, b);
	else if (i->f == 5)
		ft_u(ft_to_uj(va_arg(i->u, uintmax_t)), i, b);
	else if (i->f == 6)
		ft_u(ft_to_uz(va_arg(i->u, ssize_t)), i, b);
	else
		ft_u(ft_to_ui(va_arg(i->u, unsigned int)), i, b);
}

void	ft_put_x(const char c, struct s_info *i)
{
	if (i->f == 1)
		ft_x(ft_to_uhh(va_arg(i->u, unsigned int)), i, c);
	else if (i->f == 2)
		ft_x(ft_to_uh(va_arg(i->u, unsigned int)), i, c);
	else if (i->f == 3)
		ft_x(va_arg(i->u, unsigned long long), i, c);
	else if (i->f == 4)
		ft_x(ft_to_ul(va_arg(i->u, unsigned long)), i, c);
	else if (i->f == 5)
		ft_x(ft_to_uj(va_arg(i->u, uintmax_t)), i, c);
	else if (i->f == 6)
		ft_x(ft_to_uz(va_arg(i->u, ssize_t)), i, c);
	else
		ft_x(ft_to_ui(va_arg(i->u, unsigned int)), i, c);
}
