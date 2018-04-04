/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:37:11 by asarandi          #+#    #+#             */
/*   Updated: 2018/03/31 04:55:14 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <wctype.h>

# define FLAG_HASHTAG	1
# define FLAG_ZERO		2
# define FLAG_MINUS		4
# define FLAG_SPACE		8
# define FLAG_PLUS		16

typedef	struct	s_placeholder
{
	int				flags;
	int				have_flags;
	int				width;
	int				have_width;
	int				precision;
	int				have_precision;
	int				length;
	int				have_length;
	char			type;
	int				have_type;
	uintmax_t		n;
	char			sign;
	int				invalid;
	char			*location;
	unsigned char	*output;
	char			*float_prefix;
	char			*float_suffix;
	int				char_count;
	int				written;
}				t_placeholder;

typedef t_placeholder	t_ph;
typedef const char		t_cc;

void			float_cosmetics(t_placeholder *ph);
int				float_round_suffix(char *str, int f);
char			*float_round_prefix(char *str, int f);
int				ft_strmatch(char *little, char *big);
int				check_more_colors(int fd, char *str);
int				check_colors(int fd, char *str);
int				color_routine(int fd, const char *restrict *format);
void			iso_time(uintmax_t t);
char			*float_itoa(uintmax_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strtoupper(char *s);
int				digits_before_point(uintmax_t n);
int				ft_printf(int fd, const char *restrict format, ...);
int				get_base(char type);
int				get_default_length(char type);
int				get_wstr_length(wchar_t *wstr);
int				init_placeholder(t_placeholder *ph);
int				is_decimal(char type);
int				is_deprecated(char type);
int				is_digit(char c);
int				is_numeric(char type);
int				is_signed(char type);
int				main_routine(int fd, t_cc *restrict *fmt, va_list *ap, int wr);
int				wchar_to_utf8(unsigned int wchar, unsigned char *output);
size_t			ft_strlen(const char *s);
unsigned char	*get_char(va_list *ap, t_placeholder *ph);
void			get_double(va_list *ap, t_placeholder *ph);
unsigned char	*get_string(va_list *ap, t_placeholder *ph);
unsigned char	*get_wchar(va_list *ap, t_placeholder *ph);
unsigned char	*get_wide_string(va_list *ap, t_placeholder *ph);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			add_precision(t_placeholder *ph);
void			add_string_precision(t_placeholder *ph);
void			add_wide_string_precision(t_placeholder *ph);
void			add_width(t_placeholder *ph);
void			binary_suffix(t_placeholder *ph, char *suffix);
void			calculate_reserve(int *reserve, t_placeholder *ph);
void			check_negative(t_placeholder *ph);
void			flag_plus(t_placeholder *ph);
void			flag_space(t_placeholder *ph);
void			format_char(t_placeholder *ph);
void			format_double(t_placeholder *ph);
void			format_hex(t_placeholder *ph);
void			format_integer(t_placeholder *ph);
void			format_invalid(t_placeholder *ph);
void			format_octal(t_placeholder *ph);
void			format_output(char type, t_placeholder *ph);
void			format_pointer(t_placeholder *ph);
void			format_string(t_placeholder *ph);
void			format_unsigned_int(t_placeholder *ph);
void			format_wide_char(t_placeholder *ph);
void			format_wide_string(t_placeholder *ph);
void			get_placeholder_flags(char **fmt, t_placeholder *placeholder);
void			get_placeholder_length(char **fmt, t_placeholder *placeholder);
void			get_placeholder_precision(char **fmt, va_list *ap, t_ph *ph);
void			get_placeholder_type(char **fmt, t_placeholder *ph);
void			get_placeholder_width(char **fmt, va_list *ap, t_ph *ph);
void			invalid_skip_forward(char **fmt, t_placeholder *ph);
void			make_non_numeric(t_placeholder *ph, va_list *ap);
void			make_numeric_output(t_placeholder *ph);
void			parse_placeholder(char **fmt, va_list *ap, t_placeholder *ph);
void			string_prefix(t_placeholder *ph, char *prefix);
void			string_suffix(t_placeholder *ph, char *suffix);
void			trim_bits(t_placeholder *ph);

#endif
