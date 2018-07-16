/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 19:57:36 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/16 03:24:15 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
void			open_file(char *arg)
{
	int		fd;
	char 	*data;

	if ((fd = open(arg, O_RDONLY)) < 0)
		md5_print_error(OPEN_ERROR);
	
	
	close (fd);
}




void			read_file(char *file)
{
	
	char 	*buf;
	int		ret;
	int		bytes;
	t_uchar	data[1024];
	t_md5	MD5_struct;

	ret = 0;
	MD5_struct = NULL;
	buf
}
*/

void		md5_file(char *file)
{
	FILE 		*file_in;
	int 		bytes;
	t_uchar		data[BUFF_SIZE];
	t_md5 		md5_struct;

	md5_init(&md5_struct);
	if (!(file_in = fopen(file, "rb")))
		md5_print_error(OPEN_ERROR);
	while ((bytes = fread(data, 1, BUFF_SIZE, file_in)) != 0)
	{
		md5_update(&md5_struct, data, bytes);
		printf("%s\n", md5_struct.input);
	}
	fclose(file_in);
}

