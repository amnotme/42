#include "main.h"

int     main(int argc, char **argv)
{
    t_queue *lex;

    lex = get_lexer("ls -la /doc .");
    print_queue(lex);
    return (0);
}
