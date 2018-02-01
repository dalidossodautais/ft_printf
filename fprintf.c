/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:49:58 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/11 00:50:04 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(int fd, char *s, ...)
{
	t_info	i;

	va_start(i.u, s);
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
	va_end(i.u);
	return (i.y + i.z);
}
