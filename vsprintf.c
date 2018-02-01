/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:19:06 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/11 00:19:08 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(char **str, char *s, va_list ap)
{
	struct s_info	i;

	va_copy(i.u, ap);
	va_copy(i.v, i.u);
	i.w = 0;
	i.x = NULL;
	i.y = 0;
	i.z = 0;
	while (*s)
	{
		if (*s == '%' && !ft_analyze(&s, &i))
			return (-1);
		if (*s != '%')
			ft_normal(&s, &i);
		s++;
	}
	ft_initc(0, &i);
	*str = i.x;
	return (i.y - 1);
}
