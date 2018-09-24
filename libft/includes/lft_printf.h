/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 15:11:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PRINTF_H
# define LFT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>

# define CONVERTERS		"diDoOuUxXcCsSpbnqQkmr"
# define NUMERICS		"diDoOuUxXpb"
# define LONG_NUMERICS	"DOU"
# define LENGTHS		"hhlljtz"
# define FLAGS			"0+- #'"

# define ERROR_MESSAGE "Error"

typedef struct	s_formatter
{
	char	length;
	char	flags;
	int		width;
	int		precision;
	int		pos;
	char	converter;
	int		index;
	int		prev_len;
}				t_formatter;

typedef struct	s_conversion
{
	char	pad;
	size_t	beg;
	size_t	end;
	int		len;
}				t_conversion;

typedef struct	s_arglist
{
	va_list	begin;
	va_list	natural;
	va_list	selected;
}				t_arglist;

typedef struct	s_date
{
	long	year;
	long	month;
	long	day;
	long	hour;
	long	min;
	long	sec;
}				t_date;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				handle_formatter(t_strbuffer *sb, const char **s,
								t_arglist *args, int prev_len);
void			parse_formatter(const char **s, t_formatter *fmt,
												t_arglist *args);
int				convert(t_strbuffer *sb, t_formatter *fmt, t_arglist *args);
int				is_flag(char c, t_formatter fmt);
int				is_length(char c, t_formatter fmt, int v);
int				check_unicode(wint_t *c);
size_t			wstrtoa(char *buff, const wchar_t *wstr);
size_t			wstrntoa(char *buff, const wchar_t *wstr, size_t n);
size_t			wchartoa(char *buff, wint_t w);
int				unsigned_integer(t_formatter *fmt,
				t_strbuffer *sb, va_list ap, int b);
int				signed_integer(t_formatter *fmt,
				t_strbuffer *sb, va_list ap, int b);
int				convert_char(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_str(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_wchar(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_wstr(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_p(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_di(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_u(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_x(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_o(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_b(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_n(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_q(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_q_up(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_k(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_r(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				convert_m(t_formatter *fmt, t_strbuffer *sb, va_list ap);
int				set_coma(t_strbuffer *bs, int len);
int				is_hexa_digit(char c);
void			init_buffers(t_strbuffer *sb1, t_strbuffer *sb2);
void			init_args(t_arglist *args, va_list ap);
void			get_arg_at(int pos, t_arglist *args);
void			trial(int ret);
void			add(t_strbuffer *sb, const char *data, size_t len);

#endif
