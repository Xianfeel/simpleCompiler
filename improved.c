#include<stdio.h>
#include"lex.h"

void factor(void);
void term(void);
void expression(void);

statements()
{
  /*
  expression();
  if(match(SEMI))
    advance();
  else
    fprint(stderr,"%d: Inserting missing semicolon\n",yylineno);
  if(!match(EOI))
    statements(); 
    */
  while(!match(EOI))
  {
    expression();
    if(match(SEMI))
      advance();
    else
      fprintf(stderr,"%d:Inserting missing semicolon\n",yylineno);
  }
}

void expression()
{
  /*expression-> term expression'*/
  
  if(!legal_lookahead(NUM_OR_ID,LP,0))
    return;
  term();
  while(match(PLUS))
  {
    advance();
    term();
  }
}

term()
{
  if(!legal_lookahead(NUM_OR_ID,LP,0))
    return;
  factor();
  while(match(TIMES))
  {
   advance();
    factor();
  }
}


factor()
{
  /*factor -> NUM_OR_ID
   *        | LP expression RP
   */
  if(!legal_lookahead(NUM_OR_ID,LP,0))
    return;
  
  if(match(NUM_OR_ID))
    advance();
  else if(match(LP))
  {
    advance();
    expression();
    if(match(RP))
      advance();
    else
      fprintf(stderr,"%d: Mismatched parenthesis\n",yylineno);
  }
  else
    fprintf(stderr,"%d Number or identifier expected\n",yylineno);
}
