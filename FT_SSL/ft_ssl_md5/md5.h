/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 04:53:29 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/15 15:30:54 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

/*
** Initializing buffers from define
*/

# define IN_A 0x67452301
# define IN_B 0xefcdab89
# define IN_C 0x98badcfe
# define IN_D 0x10325476


/*
** Defining Macros of functions
*/

# define LEFTROT (x, c) (((x) << (c)) | ((X) >> (32 - (c))))

/*
** These are the basic MD5 functions. 
*/

# define F(x, y, z) (((x) & (y)) | ((˜x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (˜z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (˜z)))

typedef unsigned int t_uint
typedef unsigned char t_uchar


typedef struct				s_md5
{
	t_uint 		count[2];
	t_uint 		buf[4];
	t_uchar		input[64];
	t_uchar		digest_message[16];
}							t_md5;



#endif
