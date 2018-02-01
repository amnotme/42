/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:10:31 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/29 14:13:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int STRINGLENGTH(char* str) {
    int i = 0;
    while (*str++)
        i++;
    return i;
}

void ft_latin(char **str, int arrlen) {
    if (arrlen > 1) {
        for (int i = 1; i < arrlen; i++) {
            int len = STRINGLENGTH(str[i]);
            if (*(str[i] + len - 1) == '2' && *(str[i] + len - 2) == '4') {
                write(1, str[i] + len - 3, 1);
                write(1, str[i], len - 3);
            } else {
                if (str[i][1] != 0)
                    write(1, (str[i] + 1), STRINGLENGTH((str[i] + 1)));
                if (str[i][0])
                    write(1, &str[i][0], 1);
                write(1, "42", 2);
                if (i < arrlen - 1)
                    write(1, " ", 1);             
            }
            if (i < arrlen - 1)
                write(1, " ", 1); 
        }
    }
    write(1, "\n", 1);
}

int main(int ac, char **ag)
{
    ft_latin(ag, ac);
    return 0;
}
