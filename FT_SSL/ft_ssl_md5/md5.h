/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 04:53:29 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/17 03:13:40 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H
# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <string.h>

/*
** Initializing buffers from define
*/

# define IN_A 				0x67452301
# define IN_B 				0xefcdab89
# define IN_C 				0x98badcfe
# define IN_D 				0x10325476

/*
** General Macros
*/

# define TRUE 				(1)
# define FALSE 				(0)
# define OPEN_ERROR 			(-1)
# define MALLOC_ERROR 			(-2)
# define READ_ERROR 			(-3)
# define FOMRAT_ERROR			(-4)
# define BUFF_SIZE			(1024)

/*
** Defining Macros of functions
*/

# define LEFTROT (x, c) (((x) << (c)) | ((x) >> (32 - (c))))

/*
** These are the basic MD5 functions.
*/

# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))

/*
** Transformation functions for rounds 1, 2, 3 and 4
*/

typedef unsigned int			t_uint;
# define FF(a, b, c, d, x, s, ac) \
  {(a) += F ((b), (c), (d)) + (x) + (t_uint)(ac); \
   (a) = LEFTROT((a), (s)); \
   (a) += (b); \
  }

# define GG(a, b, c, d, x, s, ac) \
  {(a) += G ((b), (c), (d)) + (x) + (t_uint)(ac); \
   (a) = LEFTROT ((a), (s)); \
   (a) += (b); \
  }

# define HH(a, b, c, d, x, s, ac) \
  {(a) += H ((b), (c), (d)) + (x) + (t_uint)(ac); \
   (a) = LEFTROT ((a), (s)); \
   (a) += (b); \
  }

# define II(a, b, c, d, x, s, ac) \
  {(a) += I ((b), (c), (d)) + (x) + (t_uint)(ac); \
   (a) = LEFTROT ((a), (s)); \
   (a) += (b); \
  }

/*
** Define Colors
*/

# define RED 				"\033[1;31m"
# define GREEN				"\033[1;32m"
# define YELLOW				"\033[1;33m"
# define PURPLE				"\033[1;34m"
# define WHITE				"\033[0m"

typedef unsigned char			t_uchar;

typedef struct				s_md5
{
	t_uint				c[2];
	t_uint				buf[4];
	t_uchar				input[64];
	t_uchar				digest_message[16];
}					t_md5;

typedef struct				s_containers
{
	t_uint				a;
	t_uint				b;
	t_uint				c;
	t_uint				d;
}					t_containers;

/*
** Globals
*/

extern int				g_s[64];
extern int				g_k[64];

/*
** MD5 functions
*/

void					open_file(char *arg);
void					read_file(char *file);
void					md5_file(char *file);
void					md5_init(t_md5 *md5_struct);
void					md5_print_error(int error_code);
void					md5_print_usage_no_params(void);
void					md5_print_usage_invalid_params(char *arg);
void					md5_update(t_md5 *md5_struct, t_uchar *data, \
					t_uint len);
void					md5_transform(t_uint *buf, t_uint *in);
void					md5_transform_round_1(t_containers *box, \
					t_uint *in, int *i);
#endif
