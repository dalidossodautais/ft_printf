/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:20:09 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 19:20:11 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wslen(const wchar_t *s, t_info *i)
{
	int		a;
	int		t;

	a = -1;
	t = 0;
	while (s[++a] && (i->a == -1 || t < i->a))
	{
		if (s[a] < 128 && (i->a == -1 || t + 1 <= i->a))
			++t;
		else if (s[a] < 2048 && (i->a == -1 || t + 2 <= i->a))
			t += 2;
		else if (s[a] < 65536 && (i->a == -1 || t + 3 <= i->a))
			t += 3;
		else if (i->a == -1 || t + 4 <= i->a)
			t += 4;
	}
	return (t);
}

int		ft_wclen(const wchar_t c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else
		return ((c < 65536) ? 3 : 4);
}

int		ft_slen(const char *s)
{
	int		a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}
