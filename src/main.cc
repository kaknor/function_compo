#include <iostream>
#include "parser.hh"

int main()
{
  Parser p = Parser("bite");
  p.parse();
  return 0;
}
