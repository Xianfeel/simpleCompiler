#include "lex.h"
#include <stdio.h>
#include <ctype.h>

char * yytext = ""; /*Lexeme (not '\0' terminated)*/
int yyleng = 0; /*Lexeme length.*/
int yylineno = 0; /*Input line number*/

lex()
{
    static char input_buffer[128];
    char * current;
    current = yytext + yyleng;

    while(1)
    {
        while(!*current)
        {
            current = input_buffer;
            if(!gets(input_buffer))
            {
                *current = '\0';
            }
        }
    }
}
