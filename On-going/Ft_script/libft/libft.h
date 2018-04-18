/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:35:28 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/09 15:08:11 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Below are the main functions for the lib
*/

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(char const *s);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *s1, char const *s2, size_t n);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strnstr(const char *big, const char *little, size_t l);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
void				*ft_strnew(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_atoi(const char *str);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Below are the t_list functions
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** Below are the extra functions
*/

int					ft_iswspace(int c);
int					ft_isprime(unsigned int num);
int					ft_even(int num);
int					ft_odd(int num);
char				*true_false(unsigned int num);
void				red(void);
void				bred(void);
void				green(void);
void				bgreen(void);
void				yellow(void);
void				byellow(void);
void				blue(void);
void				bblue(void);
void				magenta(void);
void				bmagenta(void);
void				cyan(void);
void				bcyan(void);
void				c_reset(void);
void				ft_atoi_handle(char const *s, int *i);
size_t				ft_wc(const char *s, char c);
size_t				ft_wl(const char *s, char c);
size_t				ft_numlength(int num, int base);
#endif
