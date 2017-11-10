/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:54:07 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 18:16:28 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void static	testn(int i)
{
	printf("****************\n");
	printf("  FUNCTION No => %d\n", i);
	printf("****************\n");
}

int		main(void)
{
	system ("clear");
	testn(1);
	char *str1;
	int ft_strlen_res = 0;
	str1 = "what";
	ft_strlen_res = ft_strlen(str1);
	printf("ft_strlen => what => %d\n", ft_strlen_res);
	str1 = "";
	ft_strlen_res = ft_strlen(str1);
	printf("ft_strlen => '' => %d\n", ft_strlen_res);

	testn(2);

	printf("  <= ft_putchar <= 'a' (it will print on the left)");
	ft_putchar('a');
	printf("\n  <= ft_putchar <= 'Z' (it will print on the left)");
	ft_putchar('Z');
	printf("\n");

	str1 = "ft_putstr => This is ft_putstr coming from a variable";
	testn(3);
	ft_putstr("ft_putstr => 'ft_putstr' => ft_putstr\n");
	ft_putstr(str1);
	ft_putstr("\n");
	str1 = "ft_putstr => abcdefghijklmnopqrstuvwxyz";
	ft_putstr(str1);
	ft_putchar('\n');
	str1 = "ft_putstr => ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
	ft_putstr(str1);
	ft_putchar('\n');

	testn(4);
	printf("ft_isalpha => 'a' %s\n", true_false(ft_isalpha('a'))); 
	printf("ft_isalpha => 'Z' %s\n", true_false(ft_isalpha('Z')));
	printf("ft_isalpha => '1' %s\n", true_false(ft_isalpha('1')));	

	testn(5);

	printf("ft_isdigit => '1' %s\n", true_false(ft_isdigit('1')));
	printf("ft_isdigit => '9' %s\n", true_false(ft_isdigit('9')));
	printf("ft_isdigit => 5 %s\n", true_false(ft_isdigit(5)));
	printf("ft_isdigit => 'a' %s\n", true_false(ft_isdigit('a')));

	testn(6);


	printf("ft_isalnum => 'a' %s\n", true_false(ft_isalnum('a')));
	printf("ft_isalnum => 'Z' %s\n", true_false(ft_isalnum('Z')));
	printf("ft_isalnum => '1' %s\n", true_false(ft_isalnum('1')));
	printf("ft_isalnum => 1 %s\n", true_false(ft_isalnum(1)));
	printf("ft_isalnum => 9 %s\n", true_false(ft_isalnum(9)));
	printf("ft_isalnum => 10 %s\n", true_false(ft_isalnum(10)));

	testn(7);

	printf("ft_isascii => 0 %s\n", true_false(ft_isascii(0)));
	printf("ft_isascii => '(' %s\n", true_false(ft_isascii('(')));
	printf("ft_isascii => '2' %s\n", true_false(ft_isascii('2')));
	printf("ft_isascii => '<' %s\n", true_false(ft_isascii('<')));
	printf("ft_isascii => 'F' %s\n", true_false(ft_isascii('F')));
	printf("ft_isascii => 'P' %s\n", true_false(ft_isascii('P')));
	printf("ft_isascii => 'd' %s\n", true_false(ft_isascii('d')));
	printf("ft_isascii => 'z' %s\n", true_false(ft_isascii('z')));
	printf("ft_isascii => '~' %s\n", true_false(ft_isascii('~')));

	printf("ft_isascii => 127 %s\n", true_false(ft_isascii(127)));
	printf("ft_isascii => 128 %s\n", true_false(ft_isascii(128)));
	printf("ft_isascii => -1 %s\n", true_false(ft_isascii(-1)));

	testn(8);

	printf("ft_isprint => ' ' %s\n", true_false(ft_isprint(' ')));
	printf("ft_isprint => '\"' %s\n", true_false(ft_isprint('\"')));
	printf("ft_isprint => '&' %s\n", true_false(ft_isprint('&')));
	printf("ft_isprint => '?' %s\n", true_false(ft_isprint('?')));
	printf("ft_isprint => '\\' %s\n", true_false(ft_isprint('\\')));
	printf("ft_isprint => '[' %s\n", true_false(ft_isprint('[')));
	printf("ft_isprint => 'A' %s\n", true_false(ft_isprint('A')));
	printf("ft_isprint => 'z' %s\n", true_false(ft_isprint('z')));
	printf("ft_isprint => '~' %s\n", true_false(ft_isprint('~')));

	printf("ft_isprint => 0  => nul %s\n", true_false(ft_isprint(0)));
	printf("ft_isprint => 10 => nl  %s\n", true_false(ft_isprint(10)));
	printf("ft_isprint => 20 => dc4 %s\n", true_false(ft_isprint(20)));
	printf("ft_isprint => 30 => rs  %s\n", true_false(ft_isprint(30)));
	printf("ft_isprint => 127 => del %s\n", true_false(ft_isprint(127)));

	testn(9);

	printf("ft_toupper => 'a' => %c\n", ft_toupper('a'));
	printf("ft_toupper => 'z' => %c\n", ft_toupper('z'));
	printf("ft_toupper => 'A' => %c\n", ft_toupper('A'));
	printf("ft_toupper => 'Z' => %c\n", ft_toupper('Z'));
	printf("ft_toupper => '1' => %c\n", ft_toupper('1'));
	printf("ft_toupper => '?' => %c\n", ft_toupper('?'));
	printf("ft_toupper => '!' => %c\n", ft_toupper('!'));

	testn(10);

	printf("ft_tolower => 'A' => %c\n", ft_tolower('A'));
	printf("ft_tolower => 'Z' => %c\n", ft_tolower('Z'));
	printf("ft_tolower => 'a' => %c\n", ft_tolower('a'));
	printf("ft_tolower => 'z' => %c\n", ft_tolower('z'));
	printf("ft_tolower => '1' => %c\n", ft_tolower('1'));
	printf("ft_tolower => '?' => %c\n", ft_tolower('?'));
	printf("ft_tolower => '!' => %c\n", ft_tolower('!'));

	testn(11);

	ft_putendl("ft_putendl => A paragraph");
	ft_putendl("ft_putendl => This is a long sentencete.");
	ft_putendl("ft_putendl => This sentence will have a newline");
	ft_putendl("ft_putendl => It will have a newline every time.");

	testn(12);

	printf("ft_strcmp => 'abcd' , 'abcd' => 0   => %d\n", ft_strcmp("abcd", "abcd"));
	printf("ft_strcmp => 'abcd' , 'ABCD' => 32  => %d\n", ft_strcmp("abcd", "ABCD"));
	printf("ft_strcmp => 'ABCD' , 'abcd' => -32 => %d\n", ft_strcmp("ABCD", "abcd"));
	printf("ft_strcmp => ' ', 'abcd'     => -65 => %d\n", ft_strcmp(" ", "abcd"));
	printf("ft_strcmp => 'abcd' , ' '    => 65  => %d \n", ft_strcmp("abcd", " "));

	testn(13);
	char *ft_strcpy_src = "this is the source";
	char ft_strcpy_dest[100];

	ft_strcpy(ft_strcpy_dest, ft_strcpy_src);
	printf("*ft_strcpy => %s\n", ft_strcpy_dest);
	ft_strcpy_src = "this is the souce for the second time";
	ft_strcpy(ft_strcpy_dest, ft_strcpy_src);
	printf("*ft_strcpy => %s\n", ft_strcpy_dest);
	ft_strcpy_src = "12345670";
	ft_strcpy(ft_strcpy_dest, ft_strcpy_src);
	printf("*ft_strcpy => %s\n", ft_strcpy_dest);

	testn(14);
	char *ft_strncpy_src = "abcdefghijklmnopqurstuvwxyz";
	char ft_strncpy_dest[100];
	char ft_strncpy_dest2[10];

	ft_strncpy(ft_strncpy_dest, ft_strncpy_src, 28);	
	printf("*ft_strncpy , len = 28, abcdefghijklmnopqrstuvwxyz => %s\n", ft_strncpy_dest);
	ft_strncpy_src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_strncpy(ft_strncpy_dest, ft_strncpy_src, 20);
	printf("*ft_strncpy , len = 20, ABCDEFGHIJKLMNOPQRSTUVWXYZ => %s\n", ft_strncpy_dest);
	ft_strncpy_src = "12345678901234567890123456";
	ft_strncpy(ft_strncpy_dest, ft_strncpy_src, 10);
	printf("*ft_strncpy , len = 10, 12345678901234567890123456 => %s\n", ft_strncpy_dest);
	ft_strncpy_src = "\0";
	ft_strncpy(ft_strncpy_dest2, ft_strncpy_src, 10);
	printf("*ft_strncpy , len = 10, 'NULL' => %s\n", ft_strncpy_dest2);	

	testn(15);

	printf("ft_strncmp => 'abcd' , 'abcd', ln = 3 => 0   => %d\n", ft_strncmp("abcd", "abcd", 3));
	printf("ft_strncmp => 'abcd' , 'ABCD', ln = 3 => 32  => %d\n", ft_strncmp("abcd", "ABCD", 3));
	printf("ft_strncmp => 'ABCD' , 'abcd', ln = 3 => -32 => %d\n", ft_strncmp("ABCD", "abcd", 3));
	printf("ft_strncmp => ' ', 'abcd'    , ln = 3 => -65 => %d\n", ft_strncmp(" ", "abcd", 3));
	printf("ft_strncmp => 'abcd' , ' '   , ln = 3 => 65  => %d \n", ft_strncmp("abcd", " ", 3));
	printf("ft_strncmp => 'abc' , 'abd'   , ln = 2 => 0  => %d \n", ft_strncmp("abc", "abd", 2));

	testn(16);

	char ft_strcat_s2[100] = " over the rainbow";
	char ft_strcat_s1[100] = "The fox jumped";
	ft_strcat(ft_strcat_s1, ft_strcat_s2);
	printf("ft_strcat => 'The fox jumped' + ' over the rainbow' => %s\n", ft_strcat_s1);
	char ft_strcat_s4[100] = " school is no. 1";
	char ft_strcat_s3[100] = "42";
	ft_strcat(ft_strcat_s3,ft_strcat_s4);
	printf("ft_strcat => '42' + ' school is no. 1' => %s\n", ft_strcat_s3);

	testn(17);

	char ft_strncat_s2[100] = " over the rainbow";
	char ft_strncat_s1[100] = "The fox jumped";
	ft_strncat(ft_strncat_s1, ft_strncat_s2, 7);
	printf("ft_strncat => 'The fox jumped' + ' over the rainbow', len = 7  => %s\n", ft_strncat_s1);
	char ft_strncat_s4[100] = " school is no. 1i";
	char ft_strncat_s3[100] = "42";
	ft_strncat(ft_strncat_s3, ft_strncat_s4, 7);
	printf("ft_strncat => '42' + ' school is no. 1', len = 7  => %s\n", ft_strncat_s3);

	testn(18);
	printf("ft_atoi =>: 333 expected 333 => %d\n",ft_atoi("333"));
	printf("ft_atoi =>: 123456789 expected 123456789 => %d\n",ft_atoi("123456789"));
	printf("ft_atoi =>: 42 expected: 42 => %d\n",ft_atoi("42"));
	printf("ft_atoi =>: -333 expected: -333 => %d\n",ft_atoi("-333"));
	printf("ft_atoi =>: -123456789 expected: -123456789 => %d\n",ft_atoi("-123456789"));
	printf("ft_atoi =>: -42 expected: -42 => %d\n",ft_atoi("-42"));
	printf("ft_atoi =>: \\f\\r\\t\\v\\n\' \'42 expected: 42 => %d\n",ft_atoi("\f\r\t\v\n 42"));
	printf("ft_atoi =>: ?!@#$*() 3245 expected: 0 => %d\n",ft_atoi("?!@#$*() 3245"));
	printf("ft_atoi =>: 42abc- 42 4242 expected: 42 => %d\n", ft_atoi("42abc- 42 4242"));
	printf("ft_atoi =>: -+42 expected: 0 => %d\n", ft_atoi("-+42"));
	printf("ft_atoi =>: +-42 expected: 0 => %d\n", ft_atoi("+-42"));
	printf("ft_atoi =>: --42 expected: 0 => %d\n", ft_atoi("--42"));    
	printf("ft_atoi =>: 2147483647 expected: 2147483647 => %d\n", ft_atoi("2147483647"));
	printf("ft_atoi =>: -2147483648 expected: -2147483648 => %d\n", ft_atoi("-2147483648"));
	printf("ft_atoi =>:'    +12  ' expected: 12 => %d\n", ft_atoi("     +12 "));
	printf("ft_atoi =>:'3147483649' expected: ?? => %d\n", atoi("3147483649"));
	printf("ft_atoi =>:'3147483649' expected: ?? => %d\n", ft_atoi("3147483649"));
	printf("ft_atoi =>:'[blank]' expected: 0 => %d\n", ft_atoi(""));

	testn(19);
	char *ft_strchr_src = "banana";
	printf("ft_strchr => 'banana', int => 97 = 'a'  expected 'anana' => %s\n", ft_strchr(ft_strchr_src, 97));
	ft_strchr_src = "quiditch";
	printf("ft_strchr => 'quiditch', int => 105 = 'i'  expected 'iditch' => %s\n", ft_strchr(ft_strchr_src, 105));
	ft_strchr_src = "a";
	printf("ft_strchr => 'a', int => 98 = 'b'  expected 'NULL' => %s\n", ft_strchr(ft_strchr_src, 98));
	ft_strchr_src = "race car";
	printf("ft_strchr => 'race car', int => '0' expected '' => %s\n", ft_strchr(ft_strchr_src, 0));

	testn(20);
	char *ft_strrchr_src = "banana";
	printf("ft_strrchr => 'banana', int => 97 = 'a'  expected 'a' => %s\n", ft_strrchr(ft_strrchr_src, 97));
	ft_strrchr_src = "quiditch";
	printf("ft_strrchr => 'quiditch', int => 105 = 'i'  expected 'itch' => %s\n", ft_strrchr(ft_strrchr_src, 105));
	ft_strrchr_src = "a";
	printf("ft_strrchr => 'a', int => 98 = 'b'  expected 'NULL' => %s\n", ft_strrchr(ft_strrchr_src, 98));
	ft_strrchr_src = "race car";
	printf("ft_strrchr => 'race car', int => '0' expected '' => %s\n", ft_strrchr(ft_strrchr_src, 0));

	testn(21);
	char ft_strlcat_src[7] = "banana";
	char ft_strlcat_dst[12] = "good";
	printf("ft_strlcat => 'banana', 'good', 12 expected: 10  => %lu\n", ft_strlcat(ft_strlcat_dst, ft_strlcat_src, 12));
	char ft_strlcat_src2[6] = "whatt";
	char ft_strlcat_dst2[15] ="he said.";
	printf("ft_strlcat => 'he said.', 'whatt', 15 expected: 13  => %lu\n",ft_strlcat(ft_strlcat_dst2, ft_strlcat_src2, 15));

	testn(22);

	const char *largestring = "Foo Bar Baz";
	const char *little = "Bar";
	char *ptr;


	ptr = ft_strstr(largestring, little);
	printf("ft_strstr => 'Foo Bar Baz', 'Bar' =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "Foo";
	ptr = ft_strstr(largestring, little);
	printf("ft_strstr => 'Foo Bar Baz', 'Foo' =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "FOO";
	ptr = ft_strstr(largestring, little);
	printf("ft_strstr => 'Foo Bar Baz', 'FOO' =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "";
	ptr = ft_strstr(largestring, little);
	printf("ft_strstr => 'Foo Bar Baz', '[empty]' => %s\n", ptr);

	testn(23);

	largestring = "Foo Bar Baz";
	little = "Foo";
	ptr = ft_strnstr(largestring, little, 2);
	printf("ft_strnstr => 'Foo Bar Baz', 'Bar', 2 =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "Foo";
	ptr = ft_strnstr(largestring, little, 6);
	printf("ft_strnstr => 'Foo Bar Baz', 'Foo', 6 =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "FOO";
	ptr = ft_strnstr(largestring, little, 1);
	printf("ft_strnstr => 'Foo Bar Baz', 'FOO', 1 =>  %s\n", ptr);
	largestring = "Foo Bar Baz";
	little = "";
	largestring = "un deux 9";

	ptr = ft_strnstr(largestring, "9", 3);
	printf("ft_strnstr => 'un deux 9', '[Null]' => %s\n", ptr);


	testn(24);
	bgreen();
	ft_putstr("ft_putchar_fd => 'a', 1 => ");
	green();
	ft_putchar_fd('a', 1);
	bgreen();
	ft_putstr("\nft_putchar_fd => 'a', 2 => ");
	red();
	ft_putchar_fd('a', 2);
	bgreen();
	ft_putstr("\nft_putchar_fd => 'a', 0 => ");
	yellow();
	ft_putchar_fd('a', 0);
	c_reset();
	ft_putchar('\n');

	testn(25);

	bgreen();
	ft_putstr("ft_putstr_fd => 'This is a string', 1 => ");
	green();
	ft_putstr_fd("This is a string", 1);
	bgreen();
	ft_putstr("\nft_putstr_fd => 'This is a string', 2 => ");
	red();
	ft_putstr_fd("This is a string", 2);
	bgreen();
	ft_putstr("\nft_putstr_fd => 'This is a string', 0 => ");
	yellow();
	ft_putstr_fd("This is a string", 0);
	c_reset();
	ft_putchar('\n');

	testn(26);

	bgreen();
	ft_putstr("ft_putstr_fd => 'This is a string with a new line', 1 => ");
	green();
	ft_putendl_fd("This is a string with a new line", 1);
	bgreen();
	ft_putstr("ft_putstr_fd => 'This is a string with a new line', 2 => ");
	red();
	ft_putendl_fd("This is a string with a new line", 2);
	bgreen();
	ft_putstr("ft_putstr_fd => 'This is a string with a new line', 0 => ");
	yellow();
	ft_putendl_fd("This is a string with a new line", 0);
	c_reset();
	ft_putchar('\n');

	testn(27);

	bgreen();
	ft_putstr("ft_putnbr => 0 => ");
	bblue();
	ft_putnbr(0);
	bgreen();
	ft_putstr("\nft_putnbr => 1 => ");
	bblue();
	ft_putnbr(1);
	bgreen();
	ft_putstr("\nft_putnbr => -1 => ");
	bblue();
	ft_putnbr(-1);
	bgreen();
	ft_putstr("\nft_putnbr => 10 => ");
	bblue();
	ft_putnbr(10);
	bgreen();
	ft_putstr("\nft_putnbr => -10 => ");
	bblue();
	ft_putnbr(-10);
	bgreen();
	ft_putstr("\nft_putnbr => 3333 => ");
	bblue();
	ft_putnbr(3333);
	bgreen();
	ft_putstr("\nft_putnbr => -3333 => ");
	bblue();
	ft_putnbr(-3333);
	bgreen();
	ft_putstr("\nft_putnbr => 42 => ");
	bblue();
	ft_putnbr(42);
	bgreen();
	ft_putstr("\nft_putnbr => -42 => ");
	bblue();
	ft_putnbr(-42);
	bgreen();
	ft_putstr("\nft_putnbr => 2147483647 => ");
	bblue();
	ft_putnbr(2147483647);
	bgreen();
	ft_putstr("\nft_putnbr => -2147483648 => ");
	bblue();
	ft_putnbr(-2147483648);
	bgreen();
	ft_putstr("\nft_putnbr => 0123 (this is octal) => ");
	bblue();
	ft_putnbr(0123);
	c_reset();
	ft_putstr("\n");

	testn(28);

	bgreen();
	ft_putstr("ft_putnbr_fd => 0, 1 => ");
	green();
	ft_putnbr_fd(0, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 1, 1 => ");
	green();
	ft_putnbr_fd(1, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -1, 1 => ");
	green();
	ft_putnbr_fd(-1, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 10, 1 => ");
	green();
	ft_putnbr_fd(10, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -10, 1 => ");
	green();
	ft_putnbr_fd(-10, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 3333, 1 => ");
	green();
	ft_putnbr_fd(3333, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -3333, 1 => ");
	green();
	ft_putnbr_fd(-3333, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 42, 1 => ");
	green();
	ft_putnbr_fd(42, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -42, 1 => ");
	green();
	ft_putnbr_fd(-42, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 2147483647, 1 => ");
	green();
	ft_putnbr_fd(2147483647, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -2147483648, 1 => ");
	green();
	ft_putnbr_fd(-2147483648, 1);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 0123, 1 (this is octal) => ");
	green();
	ft_putnbr_fd(0123, 1);
	c_reset();
	ft_putstr("\n\n");

	bgreen();
	ft_putstr("ft_putnbr_fd => 0, 2 => ");
	red();
	ft_putnbr_fd(0, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 1, 2 => ");
	red();
	ft_putnbr_fd(1, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -1, 2 => ");
	red();
	ft_putnbr_fd(-1, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 10, 2 => ");
	red();
	ft_putnbr_fd(10, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -10, 2 => ");
	red();
	ft_putnbr_fd(-10, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 3333, 2 => ");
	red();
	ft_putnbr_fd(3333, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -3333, 2 => ");
	red();
	ft_putnbr_fd(-3333, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 42, 2 => ");
	red();
	ft_putnbr_fd(42, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -42, 2 => ");
	red();
	ft_putnbr_fd(-42, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 2147483647, 2 => ");
	red();
	ft_putnbr_fd(2147483647, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -2147483648, 2 => ");
	red();
	ft_putnbr_fd(-2147483648, 2);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 0123, 2 (this is octal) => ");
	red();
	ft_putnbr_fd(0123, 2);
	c_reset();
	ft_putstr("\n\n");

	bgreen();
	ft_putstr("ft_putnbr_fd => 0, 0 => ");
	yellow();
	ft_putnbr_fd(0, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 1, 0 => ");
	yellow();
	ft_putnbr_fd(1, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -1, 0 => ");
	yellow();
	ft_putnbr_fd(-1, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 10, 0 => ");
	yellow();
	ft_putnbr_fd(10, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -10, 0 => ");
	yellow();
	ft_putnbr_fd(-10, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 3333, 0 => ");
	yellow();
	ft_putnbr_fd(3333, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -3333, 0 => ");
	yellow();
	ft_putnbr_fd(-3333, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 42, 0 => ");
	yellow();
	ft_putnbr_fd(42, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -42, 0 => ");
	yellow();
	ft_putnbr_fd(-42, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 2147483647, 0 => ");
	yellow();
	ft_putnbr_fd(2147483647, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => -2147483648, 0 => ");
	yellow();
	ft_putnbr_fd(-2147483648, 0);
	bgreen();
	ft_putstr("\nft_putnbr_fd => 0123, 0 (this is octal) => ");
	yellow();
	ft_putnbr_fd(0123, 0);
	c_reset();
	ft_putstr("\n");

	testn(29);
	green();
	char ft_memset_src[50] = "GeeksForGeeks is for programming geeks.";
	ft_putstr("\nft_memset => Before memset(): ");
	ft_putendl(ft_memset_src);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_memset(ft_memset_src + 13, '.', 8);
	ft_putstr("ft_memset => After memset():  ");
	ft_putendl(ft_memset_src);

	green();
	char ft_memset_src2[50] = "Leopoldo Hernandez Oliva";
	ft_putstr("\nft_memset => Before memset(): ");
	ft_putendl(ft_memset_src2);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_memset(ft_memset_src2 + 9, '#', 9);
	ft_putstr("ft_memset => After memset():  ");
	ft_putendl(ft_memset_src2);
	c_reset();

	testn(30);

	green();
	char ft_bzero_src[50] = "GeeksForGeeks is for programming geeks.";
	ft_putstr("\nft_bzero => Before ft_bzero(): ");
	ft_putendl(ft_bzero_src);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_bzero(ft_bzero_src + 13, 8);
	ft_putstr("ft_bzero => After ft_bzero():  ");
	ft_putendl(ft_bzero_src);

	green();
	char ft_bzero_src2[50] = "Leopoldo Hernandez Oliva";
	ft_putstr("\nft_bzero => Before bzero(): ");
	ft_putendl(ft_bzero_src2);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_bzero(ft_bzero_src2 + 9, 9);
	ft_putstr("ft_bzero => After bzero():  ");
	ft_putendl(ft_bzero_src2);
	c_reset();

	testn(31);
	green();
	char ft_memcpy_src[50] = "GeeksForGeeks is for programming geeks.";
	char ft_memcpy_dst[50];
	ft_putstr("\ft_memcpy => (in source) 'GeeksForGeeks is for programming geeks. :");
	ft_putendl(ft_memcpy_src);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_memcpy(ft_memcpy_dst, ft_memcpy_src, 13);
	ft_putstr("ft_memcpy => (in destination) => 13 bytes copied:  ");
	ft_putendl(ft_memcpy_dst);

	green();
	char ft_memcpy_src2[50] = "Leopoldo Hernandez Oliva";
	char ft_memcpy_dst2[50];
	ft_putstr("\nft_memcpy => (in source) : ");
	ft_putendl(ft_memcpy_src2);
	// Fill 8 characters starting from str[13] with '.'
	red();
	ft_memcpy(ft_memcpy_dst2, ft_memcpy_src2, 9);
	ft_putstr("ft_memcpy => (in destination) => 9 bytes copied: ");
	ft_putendl(ft_memcpy_dst2);
	c_reset();



	/*
	   testn(-1);
	   printf("ft_isprime => '2'            => 'TRUE', %s\n", true_false(ft_isprime(2)));
	   printf("ft_isprime => '3'            => 'TRUE', %s\n", true_false(ft_isprime(3)));
	   printf("ft_isprime => '5'            => 'TRUE', %s\n", true_false(ft_isprime(5)));
	   printf("ft_isprime => '11'           => 'TRUE', %s\n", true_false(ft_isprime(11)));
	   printf("ft_isprime => '829'          => 'TRUE', %s\n", true_false(ft_isprime(829)));
	   printf("ft_isprime => '24571'        => 'TRUE', %s\n", true_false(ft_isprime(24571)));
	   printf("ft_isprime => '25423'        => 'TRUE', %s\n", true_false(ft_isprime(25423)));
	   printf("ft_isprime => '56779'        => 'TRUE', %s\n", true_false(ft_isprime(56779)));
	   printf("ft_isprime => '104723'       => 'TRUE', %s\n", true_false(ft_isprime(104723)));

	   printf("ft_isprime => '-1'           => 'FALSE', %s\n", true_false(ft_isprime(-1)));
	   printf("ft_isprime => '0'            => 'FALSE', %s\n", true_false(ft_isprime(0)));
	   printf("ft_isprime => '1'            => 'FALSE', %s\n", true_false(ft_isprime(1)));
	   printf("ft_isprime => '4'            => 'FALSE', %s\n", true_false(ft_isprime(4)));
	   printf("ft_isprime => '1000'         => 'FALSE', %s\n", true_false(ft_isprime(1000)));
	   printf("ft_isprime => '100000'       => 'FALSE', %s\n", true_false(ft_isprime(100000)));
	   printf("ft_isprime => '2147483647'   => 'TRUE', %s\n", true_false(ft_isprime(2147483647)));

	   testn(-2);

	   printf("ft_even => '-2147483642'     => 'TRUE', %s\n", true_false(ft_even(-2147483642)));
	   printf("ft_even => '-21474836'     => 'TRUE', %s\n", true_false(ft_even(-21474836)));
	   printf("ft_even => '-21474'     => 'TRUE', %s\n", true_false(ft_even(-21474)));
	   printf("ft_even => '-214'     => 'TRUE', %s\n", true_false(ft_even(-214)));
	   printf("ft_even => '0'     => 'TRUE', %s\n", true_false(ft_even(0)));
	   printf("ft_even => '2147483646'     => 'TRUE', %s\n", true_false(ft_even(2147483646)));
	   printf("ft_even => '21474836'     => 'TRUE', %s\n", true_false(ft_even(21474836)));
	   printf("ft_even => '214748'     => 'TRUE', %s\n", true_false(ft_even(214748)));
	   ft_putchar('\n');
	   printf("ft_even => '-2147483647'     => 'FALSE', %s\n", true_false(ft_even(-2147483647)));
	   printf("ft_even => '-214743'     => 'FALSE', %s\n", true_false(ft_even(-214743)));
	   printf("ft_even => '-21'     => 'FALSE', %s\n", true_false(ft_even(-21)));
	   printf("ft_even => '-1'     => 'FALSE', %s\n", true_false(ft_even(-1)));
	   printf("ft_even => '1'     => 'FALSE', %s\n", true_false(ft_even(1)));
	   printf("ft_even => '21'     => 'FALSE', %s\n", true_false(ft_even(21)));
	   printf("ft_even => '2147'     => 'FALSE', %s\n", true_false(ft_even(2147)));
	   printf("ft_even => '2147483'     => 'FALSE', %s\n", true_false(ft_even(2147483)));
	   printf("ft_even => '2147483648'     => 'FALSE', %s\n", true_false(ft_even(2147483648)));

	   testn(-3);
	   printf("ft_odd => '-2147483642'     => 'FALSE', %s\n", true_false(ft_odd(-2147483642)));
	   printf("ft_odd => '-21474836'     => 'FALSE', %s\n", true_false(ft_odd(-21474836)));
	   printf("ft_odd => '-21474'     => 'FALSE', %s\n", true_false(ft_odd(-21474)));
	   printf("ft_odd => '-214'     => 'FALSE', %s\n", true_false(ft_odd(-214)));
	   printf("ft_odd => '0'     => 'FALSE', %s\n", true_false(ft_odd(0)));
	   printf("ft_odd => '2147483646'     => 'FALSE', %s\n", true_false(ft_odd(2147483646)));
	   printf("ft_odd => '21474836'     => 'FALSE', %s\n", true_false(ft_odd(21474836)));
	   printf("ft_odd => '214748'     => 'FALSE', %s\n", true_false(ft_odd(214748)));
	   ft_putchar('\n');
	   printf("ft_odd => '-2147483647'     => 'TRUE', %s\n", true_false(ft_odd(-2147483647)));
	   printf("ft_odd => '-214743'     => 'TRUE', %s\n", true_false(ft_odd(-214743)));
	   printf("ft_odd => '-21'     => 'TRUE', %s\n", true_false(ft_odd(-21)));
	   printf("ft_odd => '-1'     => 'TRUE', %s\n", true_false(ft_odd(-1)));
	   printf("ft_odd => '1'     => 'TRUE', %s\n", true_false(ft_odd(1)));
	   printf("ft_odd => '21'     => 'TRUE', %s\n", true_false(ft_odd(1)));
	   printf("ft_odd => '2147'     => 'TRUE', %s\n", true_false(ft_odd(2147)));
	   printf("ft_odd => '2147483'     => 'TRUE', %s\n", true_false(ft_odd(2147483)));
	   printf("ft_odd => '2147483648'     => 'FALSE', %s\n", true_false(ft_odd(2147483648)));

	   testn(-4);
	   green();	
	   printf("true_false => 1 = 'TRUE' =>, %s\n", true_false(1));
	   red();
	   printf("true_false => 0 = 'FALSE' =>, %s\n", true_false(0));
	   yellow();
	   printf("true_false => 10 = 'incorrect input' =>, %s\n", true_false(10));
	   c_reset();	
	   testn(-5);

	red();
	ft_putendl("RED");
	bred();
	ft_putendl("BOLD RED");
	green();
	ft_putendl("GREEN");
	bgreen();
	ft_putendl("BOLD GREEN");
	yellow();
	ft_putendl("YELLOW");
	byellow();
	ft_putendl("BOLD YELLOW");
	blue();
	ft_putendl("BLUE");
	bblue();
	ft_putendl("BOLD BLUE");
	magenta();
	ft_putendl("MAGENTA");
	bmagenta();
	ft_putendl("BOLD MAGENTA");
	cyan();
	ft_putendl("CYAN");
	bcyan();
	ft_putendl("BOLD CYAN");
	c_reset();
	ft_putendl("RESET TO WHITE");
	*/

		return (0);
}
