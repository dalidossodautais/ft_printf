/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   informations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:25:57 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 21:26:01 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dollar(char **s, t_info *i)
{
	int		a;

	a = 0;
	while ((*s)[a] >= '0' && (*s)[a] <= '9')
		a++;
	if ((*s)[a] != '$')
		return ;
	a = 0;
	while (**s >= '0' && **s <= '9')
	{
		a = a * 10 + **s - '0';
		++*s;
	}
	va_copy(i->u, i->v);
	while (--a)
		va_arg(i->u, int);
	++*s;
}

void	ft_length(char **s, t_info *i)
{
	i->d = 0;
	if (**s == '*')
	{
		i->d = va_arg(i->u, int);
		++*s;
		if (i->d < 0)
		{
			i->c = 2;
			i->d *= -1;
		}
	}
	else
		while (**s >= '0' && **s <= '9')
		{
			i->d = i->d * 10 + **s - '0';
			++*s;
		}
}

void	ft_precision(char **s, t_info *i)
{
	++*s;
	i->a = 0;
	if (**s == '*')
	{
		++*s;
		ft_dollar(s, i);
		if ((i->a = va_arg(i->u, int)) < 0)
			i->a = -1;
	}
	else if (**s == '-')
	{
		++*s;
		while (**s >= '0' && **s <= '9')
			++*s;
	}
	else
		while (**s >= '0' && **s <= '9')
		{
			i->a = i->a * 10 + **s - '0';
			++*s;
		}
}

void	ft_attribute(const char c, t_info *i)
{
	if (c == '#')
		i->b = 1;
	else if (c == '0' && i->a == -1 && i->c == 0)
		i->c = 1;
	else if (c == '-')
		i->c = 2;
	else if (c == ' ' && i->e == 0)
		i->e = ' ';
	else if (c == '+')
		i->e = '+';
}

void	ft_modifier(char **s, t_info *i)
{
	if (**s == 'h' && *(*s + 1) == 'h' && !i->f)
		i->f = 1;
	else if (**s == 'h' && *(*s + 1) != 'h' && i->f < 2)
		i->f = 2;
	else if ((**s == 'l' && *(*s + 1) == 'l') || **s == 'q')
		i->f = 3;
	else if (**s == 'l')
		i->f = 4;
	else if (**s == 'j')
		i->f = 5;
	else if (**s == 'z')
		i->f = 6;
	else if (**s == 'L')
		i->f = 7;
	if ((**s == 'h' && *(*s + 1) == 'h') || (**s == 'l' && *(*s + 1) == 'l'))
		*s += 2;
	else if (**s == 'h' || **s == 'l' || **s == 'j' || **s == 'z' ||
		**s == 'q' || **s == 'L')
		++*s;
}
