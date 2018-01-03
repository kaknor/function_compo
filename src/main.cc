#include <iostream>
#include "parser.hh"
#include "lexer.hh"

int main()
{
  Parser p = Parser("bite");
  Lexer l = Lexer();
  p.eat("bite");
  return 0;
}
