#include "lexer.hh"

// TODO : Create an array with all separator.
bool Lexer::eat(std::string *content, std::string::iterator *cur, std::string token)
{
  std::string::iterator it = *cur;
  for (; *it != ' ' || *it != '\t'; it++)
    continue;
  unsigned spaces = 0;
  for (std::string::iterator i = it ; *i == ' '; i++)
    spaces++;
  auto b = std::distance(content->begin(), *cur);
  auto e = std::distance(*cur, it);
  std::string s = content->substr(b, e);
  if (s == token)
    {
      *cur += e + spaces;
      return true;
    }
  return false;
}
