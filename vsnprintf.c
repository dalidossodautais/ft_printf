/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsnprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:47:46 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/11 00:47:59 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsnprintf(char **str, size_t size, char *s, va_list ap)
{
	struct s_info	i;

	va_copy(i.u, ap);
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
	*str = i.x;
	if (i.y > (int)size)
		(*str)[size - 1] = 0;
	return (i.y - 1);
}
