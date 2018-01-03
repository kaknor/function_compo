#include <iostream>
#include "parser.hh"

int main()
{
  std::cout << "Wesh maggl !" << std::endl;
  Parser p = Parser("bite");
  p.read_file();
  return 0;
}
