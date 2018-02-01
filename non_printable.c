/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:10:08 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/16 19:10:09 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_non_printable3(const char c)
{
	if (c == 26)
		return ("SUB");
	if (c == 27)
		return ("ESC");
	if (c == 28)
		return ("FS");
	if (c == 29)
		return ("GS");
	if (c == 30)
		return ("RS");
	if (c == 31)
		return ("US");
	return ((c == 127) ? "DEL" : "(null)");
}

static char	*ft_non_printable2(const char c)
{
	if (c == 13)
		return ("CR");
	if (c == 14)
		return ("SO");
	if (c == 15)
		return ("SI");
	if (c == 16)
		return ("DLE");
	if (c == 17)
		return ("DC1");
	if (c == 18)
		return ("DC2");
	if (c == 19)
		return ("DC3");
	if (c == 20)
		return ("DC4");
	if (c == 21)
		return ("NAK");
	if (c == 22)
		return ("SYN");
	if (c == 23)
		return ("ETB");
	if (c == 24)
		return ("CAN");
	return ((c == 25) ? "EM" : ft_non_printable3(c));
}

char		*ft_non_printable(const char c)
{
	if (c == 0)
		return ("NUL");
	if (c == 1)
		return ("SOH");
	if (c == 2)
		return ("STX");
	if (c == 3)
		return ("ETX");
	if (c == 4)
		return ("EOT");
	if (c == 5)
		return ("ENQ");
	if (c == 6)
		return ("ACK");
	if (c == 7)
		return ("BEL");
	if (c == 8)
		return ("BS");
	if (c == 9)
		return ("HT");
	if (c == 10)
		return ("LF");
	if (c == 11)
		return ("VT");
	return ((c == 12) ? "FF" : ft_non_printable2(c));
}
