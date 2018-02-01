/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:39:36 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 18:39:37 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_unicode(wchar_t c, t_info *i)
{
	if (c < 0x80 || (MB_CUR_MAX == 1))
		ft_initc(ft_to_hh(c), i);
	else if (c < 0x800)
	{
		ft_initc(c / 0x40 + 0xC0, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
	else if (c < 0x10000)
	{
		ft_initc(c / 0x1000 + 0xE0, i);
		ft_initc(c / 0x40 - c / 0x1000 * 0x40 + 0x80, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
	else
	{
		ft_initc(c / 0x40000 + 0xF0, i);
		ft_initc(c / 0x1000 - c / 0x40000 * 0x1000 + 0x80, i);
		ft_initc(c / 0x40 - c / 0x1000 * 0x40 + 0x80, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
}

void		ft_c(const char c, t_info *i)
{
	if (!i->c)
		while (--i->d > 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (--i->d > 0)
			ft_initc('0', i);
	ft_initc(c, i);
	if (i->c == 2)
		while (--i->d > 0)
			ft_initc(' ', i);
}

int			ft_lc(const wchar_t c, t_info *i)
{
	if (!(c < 0x160 || (c < 2048 && MB_CUR_MAX > 1) || (c < 65536 &&
		MB_CUR_MAX > 2) || MB_CUR_MAX > 3))
		return (0);
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	ft_unicode(c, i);
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
	return (1);
}
