#include "parser.hh"

std::string Parser::read_file()
{
  std::ifstream file(this->name);
  std::stringstream buff;
  buff << file.rdbuf();
  return buff.str();
}

bool Parser::eat(std::string token)
{
  std::string::iterator it = this->cur;
  for (; *it != ' '; it++)
    continue;
  unsigned spaces = 0;
  for (std::string::iterator i = it ; *i == ' '; i++)
    spaces++;
  auto b = std::distance(this->content.begin(), this->cur);
  auto e = std::distance(this->cur, it);
  std::string s = this->content.substr(b, e);
  if (s == token)
    {
      this->cur += e + spaces;
      return true;
    }
  return false;
}
