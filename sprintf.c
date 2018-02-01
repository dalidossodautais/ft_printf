/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:03:56 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/03 22:03:57 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprintf(char **str, char *s, ...)
{
	struct s_info	i;

	va_start(i.u, s);
	va_copy(i.v, i.u);
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
	ft_initc(0, &i);
	va_end(i.u);
	*str = i.x;
	return (i.y - 1);
}
