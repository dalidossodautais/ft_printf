/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 22:43:34 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/05/30 12:59:02 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <inttypes.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_info
{
	int		a;
	char	b;
	char	c;
	int		d;
	char	e;
	char	f;
	int		g;
	va_list	u;
	va_list	v;
	int		w;
	char	*x;
	int		y;
	int		z;
}				t_info;

int				ft_printf(char *s, ...);
int				ft_sprintf(char **str, char *s, ...);
int				ft_snprintf(char **str, size_t size, char *s, ...);
void			ft_normal(char **s, t_info *i);

int				ft_analyze(char **s, t_info *i);
int				ft_sanalyze(char **s, t_info *i);
void			ft_dollar(char **s, t_info *i);
void			ft_length(char **s, t_info *i);
void			ft_precision(char **s, t_info *i);
void			ft_attribute(const char c, t_info *i);
void			ft_modifier(char **s, t_info *i);

int				ft_put(const char c, t_info *i);
void			ft_put_d(t_info *i);
void			ft_put_o(t_info *i);
void			ft_put_u(const char b, t_info *i);
void			ft_put_x(const char c, t_info *i);

char			ft_to_hh(char n);
short int		ft_to_h(short int n);
int				ft_to_i(int n);
long			ft_to_l(long n);
intmax_t		ft_to_j(intmax_t n);
size_t			ft_to_z(size_t n);

unsigned char	ft_to_uhh(unsigned char n);
unsigned short	ft_to_uh(unsigned short int n);
unsigned int	ft_to_ui(unsigned int n);
unsigned long	ft_to_ul(unsigned long n);
uintmax_t		ft_to_uj(uintmax_t n);
ssize_t			ft_to_uz(ssize_t n);
double			ft_to_d(double n);

void			ft_inits(const char *s, t_info *i);
void			ft_initc(const char c, t_info *i);
int				ft_wslen(const wchar_t *s, t_info *i);
int				ft_wclen(const wchar_t c);
int				ft_slen(const char *s);
char			*ft_non_printable(const char c);

void			ft_c(const char c, t_info *i);
int				ft_lc(const wchar_t c, t_info *i);
void			ft_s(char *s, t_info *i);
int				ft_ls(wchar_t *s, t_info *i);

void			ft_d(long long n, t_info *i);
void			ft_o(unsigned long long n, t_info *i);
void			ft_p(unsigned long long n, t_info *i);
void			ft_u(unsigned long long n, t_info *i, const char b);
void			ft_x(unsigned long long n, t_info *i, const char c);

void			ft_e(long double n, t_info *i, char c);
void			ft_f(long double n, t_info *i);

void			ft_k(int fd, t_info *i);
void			ft_m(const char *s, t_info *i);

#endif
