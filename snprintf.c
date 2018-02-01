/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 01:05:38 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 01:05:40 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_snprintf(char **str, size_t size, char *s, ...)
{
	struct s_info	i;

	va_start(i.u, s);
	va_copy(i.v, i.u);
	i.w = 0;
	i.x = NULL;
	i.y = 0;
	i.z = 0;
	while (*s && i.y < (int)size)
	{
		if (*s == '%' && !ft_analyze(&s, &i))
			return (-1);
		if (*s != '%')
			ft_normal(&s, &i);
		s++;
	}
	ft_initc(0, &i);
	va_end(i.u);
	*str = i.x;
	if (i.y > (int)size)
		(*str)[size - 1] = 0;
	return ((i.y > (int)size) ? size - 1 : i.y - 1);
}
