#include "parser.hh"

void Parser::read_file()
{
  std::ifstream file(this->file);
  for (std::string line; std::getline(file, line);)
    std::cout << line << "\n";
  std::cout << std::endl;
}
