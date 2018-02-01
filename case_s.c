/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:42:03 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 18:42:04 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_set(wchar_t *s, t_info *i)
{
	int	a;

	a = -1;
	while (s[++a] && i->a < a)
		if (!(s[a] < 0x160 || (s[a] < 0x800 && MB_CUR_MAX > 1) ||
			(s[a] < 65536 && MB_CUR_MAX > 2) || MB_CUR_MAX > 3))
			return (0);
	return (1);
}

static void	ft_unicode(wchar_t c, t_info *i)
{
	if ((c < 0x80 || (MB_CUR_MAX == 1 && i->a != -1)) && (i->a == -1 ||
		(i->a -= 1) >= 0))
		ft_initc(ft_to_hh(c), i);
	else if (c < 0x800 && (i->a == -1 || (i->a -= 2) >= 0))
	{
		ft_initc(c / 0x40 + 0xC0, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
	else if (c < 0x10000 && (i->a == -1 || (i->a -= 3) >= 0))
	{
		ft_initc(c / 0x1000 + 0xE0, i);
		ft_initc(c / 0x40 - c / 0x1000 * 0x40 + 0x80, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
	else if (i->a == -1 || (i->a -= 4) >= 0)
	{
		ft_initc(c / 0x40000 + 0xF0, i);
		ft_initc(c / 0x1000 - c / 0x40000 * 0x1000 + 0x80, i);
		ft_initc(c / 0x40 - c / 0x1000 * 0x40 + 0x80, i);
		ft_initc(c % 0x40 + 0x80, i);
	}
}

void		ft_s(char *s, t_info *i)
{
	if (!s)
		s = "(null)";
	i->d -= (ft_slen(s) < i->a || i->a == -1) ? ft_slen(s) : i->a;
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	if (i->a == -1)
		ft_inits(s, i);
	else
		while (*s && i->a-- > 0)
			ft_initc(*s++, i);
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
}

int			ft_ls(wchar_t *s, t_info *i)
{
	int		a;

	a = -1;
	if (!s)
		s = L"(null)";
	if (!ft_check_set(s, i))
		return (0);
	i->d -= ft_wslen(s, i);
	if (!i->c)
		while (i->d-- > 0)
			ft_initc(' ', i);
	if (i->c == 1)
		while (i->d-- > 0)
			ft_initc('0', i);
	if (i->a == -1)
		while (*s)
			ft_unicode(*s++, i);
	else
		while (*s && i->a > 0)
			ft_unicode(*s++, i);
	if (i->c == 2)
		while (i->d-- > 0)
			ft_initc(' ', i);
	return (1);
}
