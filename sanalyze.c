/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanalyze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:06:25 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/03 22:06:26 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initialize(struct s_info *i)
{
	i->a = -1;
	i->b = 0;
	i->c = 0;
	i->d = 0;
	i->e = 0;
	i->f = 0;
}

static void	ft_fill(char **s, struct s_info *i)
{
	while (**s == '.' || (**s >= '0' && **s <= '9') || **s == '#' ||
		**s == '-' || **s == ' ' || **s == '+' || **s == 'l' || **s == 'h' ||
		**s == 'j' || **s == 'z' || **s == 'q' || **s == 'L' || **s == '*')
	{
		if (**s == '.')
			ft_precision(s, i);
		if ((**s > '0' && **s <= '9') || **s == '*')
			ft_length(s, i);
		if (**s == '0' || **s == '#' || **s == '-' || **s == ' ' || **s == '+')
		{
			ft_attribute(**s, i);
			++*s;
		}
		if (**s == 'l' || **s == 'h' || **s == 'j' || **s == 'z' ||
			**s == 'q' || **s == 'L')
			ft_modifier(s, i);
	}
}

int			ft_sanalyze(char **s, struct s_info *i)
{
	ft_initialize(i);
	++*s;
	ft_fill(s, i);
	if (i->c == 1 && i->a != -1 && **s && (**s == 'd' || **s == 'i' ||
		**s == 'o' || **s == 'u' || **s == 'x' || **s == 'X' || **s == 'e' ||
		**s == 'E' || **s == 'f' || **s == 'F' || **s == 'g' || **s == 'G' ||
		**s == 'a' || **s == 'A' || **s == 'p' || **s == 'n' || **s == 'b' ||
		**s == 'v' || **s == 'm'))
		i->c = 0;
	if (**s)
		return (ft_put(**s, i));
	else
		--*s;
	return (1);
}
