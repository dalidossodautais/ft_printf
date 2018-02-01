/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:50:12 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/11 00:50:15 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(int fd, char *s, va_list ap)
{
	struct s_info	i;

	va_copy(i.u, ap);
	va_copy(i.v, i.u);
	i.g = fd;
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
	if (i.y)
		write(i.g, i.x, i.y);
	free(i.x);
	return (i.y + i.z);
}
