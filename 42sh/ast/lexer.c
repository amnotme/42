#include "lexer.h"

t_queue     *get_lexer(char *str)
{
    t_queue *lex;
    char    *word;

    lex = NULL;
    word = NULL;
    int i = 0;
    while (str && *str && (*str == ' ' || *str == '\t'))
        str++;
    while (str && *str && (word = ft_strword(str)))
    {
        if (!(lex = queue_enqueue(lex, queue_new(word))))
            return (NULL);
        str = str + ft_strlen(word);
        while (str && *str && (*str == ' ' || *str == '\t'))
            str++;
    }
    return (lex);
}

