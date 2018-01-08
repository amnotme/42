#include "bistro.h"

int bra_char(char c)
{
    if (c == '(')
        return (1);
    else if (c == ')')
        return (-1);
    else
        return (0);
}

int check_brackets(char *format)
{
    double	total;

    total = 1.0;
    while (*format)
    {
        printf("bra_char return: %d\n", bra_char(*format));
        if (bra_char(*format) > 0)
            total = (total * 10) + bra_char(*format);
        else if (bra_char(*format) < 0)
            total = ((total + bra_char(*format)) / 10);
        if (total < 0)
            break ;
        printf("total: %f\n", total);
        format++;
    }
    return (total);
}

void	ft_calc(char *av1, char *av2)
{
    ft_putstr("here");
}

int main(int argc, char **argv)
{
    if (argc != 3)
        ft_putendl("usage: ./calc base input_size");
    else
        ft_calc(argv[1], argv[2]);
}


