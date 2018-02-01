/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 20:24:53 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/13 20:24:55 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_inits(const char *s, t_info *i)
{
	char	*n;
	int		a;
	int		b;

	a = ft_slen(s);
	b = -1;
	n = (char *)malloc(sizeof(char) * (i->y + a));
	while (++b < i->y)
		n[b] = i->x[b];
	free(i->x);
	i->x = n;
	b = -1;
	while (++b < a)
		i->x[i->y + b] = s[b];
	i->y += a;
}

void	ft_initc(const char c, t_info *i)
{
	char	*n;
	int		a;

	a = -1;
	n = (char *)malloc(sizeof(char) * (i->y + 1));
	while (++a < i->y)
		n[a] = i->x[a];
	free(i->x);
	i->x = n;
	i->x[i->y] = c;
	i->y++;
}
