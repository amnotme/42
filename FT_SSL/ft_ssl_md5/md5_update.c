/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 23:52:42 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/17 02:19:10 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static void		md5_update_init(t_md5 *md5, t_uint len, int *bytes)
{
	*bytes = (int)((md5->c[0] >> 3) & 63);
		if ((md5->c[0] + ((t_uint)len << 3)) < md5->c[0])
		md5->c[1]++;
	md5->c[0] = md5->c[0] + ((t_uint)len << 3);
	md5->c[1] = md5->c[1] + ((t_uint)len >> 29);
}

void			md5_update(t_md5 *md5, t_uchar *data, t_uint len)
{
	int		number_bytes;
	t_uint	buf[16];
	t_uint	i[2];

	i[0] = 0;
	i[1] = 0;
	md5_update_init(md5, len, &number_bytes);	
	while (len--)
	{
		md5->input[number_bytes++] = *data++;
		if (number_bytes == 64)
		{
			while (i[0] < 16)
			{
				buf[i[0]] = ((t_uint)md5->input[i[1] + 3]) << 24 | \
							((t_uint)md5->input[i[1] + 2]) << 16 | \
							((t_uint)md5->input[i[1] + 1]) << 8 | \
							((t_uint)md5->input[i[1]]);
				i[0] = i[0] + 1;
				i[1] = i[1] + 4;
			}
			number_bytes = 0;
			printf("here");
			md5_transform(md5->buf, buf);
		}
	}
}
