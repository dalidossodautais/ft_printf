/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 23:42:55 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/10 23:42:57 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_normal(char **s, struct s_info *i)
{
	char		*t;
	long long	a;
	long long	b;

	a = 0;
	while ((*s)[a] && (*s)[a] != '%')
		a++;
	t = (char *)malloc(sizeof(char) * (i->y + a));
	b = -1;
	while (++b < i->y)
		t[b] = i->x[b];
	b = -1;
	while (++b < a)
		t[i->y + b] = (*s)[b];
	free(i->x);
	i->x = t;
	i->y += a;
	*s += a - 1;
}
