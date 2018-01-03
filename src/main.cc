#include <iostream>
#include "parser.hh"

int main()
{
  Parser p = Parser("bite");
  p.eat("bite");
  return 0;
}
