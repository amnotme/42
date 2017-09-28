/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:35:28 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/28 02:51:07 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
size_t	ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strncat(char *restrict s1, char const *restrict s2, size_t n);
char	*ft_strcat(char *restrict s1, char const *restrict s2);
char	*ft_strncpy(char *dst, char const *src, size_t len);
char	*ft_strcpy(char *dst, char const *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strstr(const char *big, const char *little);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** Extra functions below
*/

int		ft_isprime(unsigned int num);
int		ft_even(int num);
int		ft_odd(int num);
char	*true_false(unsigned int num);
void	red(void);
void	bred(void);
void	green(void);
void	bgreen(void);
void	yellow(void);
void	byellow(void);
void	blue(void);
void	bblue(void);
void	magenta(void);
void	bmagenta(void);
void	cyan(void);
void	bcyan(void);
void	c_reset(void);
void	c_reset(void);
#endif
