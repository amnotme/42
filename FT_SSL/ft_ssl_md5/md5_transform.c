/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 02:16:15 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/17 03:08:54 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

///static void	md5_transform_helper(

void		md5_transform_round_1(t_containers *box, t_uint *in, int *i)
{
	FF( box->a, box->b, box->c, box->d, in[0], g_s[0], 3614090360); /* 1 */
//	FF ( box->d, box->a, box->b, box->c, in[ 1], g_s[i++], 3905402710); /* 2 */
//	FF ( box->c, box->d, box->a, box->b, in[ 2], g_s[i++],  606105819); /* 3 */
//	FF ( box->b, box->c, box->d, box->a, in[ 3], g_s[i++], 3250441966); /* 4 */
//	FF ( box->a, box->b, box->c, box->d, in[ 4], g_s[i++], 4118548399); /* 5 */
//	FF ( box->d, box->a, box->b, box->c, in[ 5], g_s[i++], 1200080426); /* 6 */
//	FF ( box->c, box->d, box->a, box->b, in[ 6], g_s[i++], 2821735955); /* 7 */
//	FF ( box->b, box->c, box->d, box->a, in[ 7], g_s[i++], 4249261313); /* 8 */
//	FF ( box->a, box->b, box->c, box->d, in[ 8], g_s[i++], 1770035416); /* 9 */
//	FF ( box->d, box->a, box->b, box->c, in[ 9], g_s[i++], 2336552879); /* 10 */
//	FF ( box->c, box->d, box->a, box->b, in[10], g_s[i++], 4294925233); /* 11 */
//	FF ( box->b, box->c, box->d, box->a, in[11], g_s[i++], 2304563134); /* 12 */
//	FF ( box->a, box->b, box->c, box->d, in[12], g_s[i++], 1804603682); /* 13 */
//	FF ( box->d, box->a, box->b, box->c, in[13], g_s[i++], 4254626195); /* 14 */
//	FF ( box->c, box->d, box->a, box->b, in[14], g_s[i++], 2792965006); /* 15 */
//	FF ( box->b, box->c, box->d, box->a, in[15], g_s[i++], 1236535329); /* 16 */
	printf("got here\n");
}

void		md5_transform(t_uint *buf, t_uint *in)
{
	t_containers 	boxes;	
	int		*i;
	
	i = 0;
	boxes.a = buf[0];
	boxes.b = buf[1];
	boxes.c = buf[2];
	boxes.d = buf[3];

	printf("num a: %d\n", boxes.a);
	printf("num b: %d\n", boxes.b);
	printf("num c: %d\n", boxes.c);
	printf("num d: %d\n", boxes.d);
	printf("in -> %d\n", in[0]);

	
	md5_transform_round_1(&boxes, in, &i);
}

