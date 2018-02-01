/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:02:59 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/19 12:03:02 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *s, ...)
{
	struct s_info	i;

	va_start(i.u, s);
	va_copy(i.v, i.u);
	i.g = 1;
	i.w = 0;
	i.x = NULL;
	i.y = 0;
	i.z = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (!ft_analyze(&s, &i))
				return (-1);
		}
		else
			ft_normal(&s, &i);
		s++;
	}
	if (i.y)
		write(i.g, i.x, i.y);
	free(i.x);
	va_end(i.u);
	return (i.y + i.z);
}
