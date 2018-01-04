#include "parser.hh"

// Read the file (named name), and return the content in a string
std::string Parser::read_file()
{
  std::ifstream file(this->name);
  std::stringstream buff;
  buff << file.rdbuf();
  return buff.str();
}

// return tuple with string of the next word plus the offset
// of this->cur
std::tuple<std::string, unsigned> Parser::get_next_word()
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
  return std::make_tuple(s, spaces + e);  
}

// lookahead of 1
std::string Parser::lookahead()
{
  std::tuple<std::string, unsigned> res = this->get_next_word();
  return std::get<0>(res);
}

// eat the next word of content. returns true if the word eaten
// is token false otherwise
void Parser::eat(std::string token)
{
  std::regex re(token);
  std::tuple<std::string, unsigned> res = this->get_next_word();
  std::string s = std::get<0>(res);
  unsigned offset = std::get<1>(res);
  if (std::regex_match(s, re))
    {
      this->cur += offset;
      return;
    }
  throw std::domain_error("The token : " + s + " is unexpected here\n");
}

// The set membership (appartenance) grammar rule
// BNF : <L> ::= <L> "<-" <Ens>
void Parser::app()
{
  try
    {
      this->list();
      this->eat("<-");
      this->ens();
    }
  catch (const std::domain_error& e)
    {
      std::cerr << "Syntax error : " << e.what();
      std::cerr << "Expected <- not : " + lookahead() << std::endl;
    }
}

// The list grammar rule
// BNF : <L> ::= <S> "," <L> | <S>
void Parser::list()
{
  try
    {
      this->symbol();
      std::string la = this->lookahead();
      if (la == ",")
	{
	  eat(",");
	  this->list();
	}
    }
  catch(const std::invalid_argument& e)
    {
      std::cerr << "Syntax error : " << e.what() << std::endl;
    }
}

// Check wheather the buffer contains either of the following
// symbols : |R, |Q, |Z or |N
void Parser::ens()
{
  try
    {
      this->eat("\\|R|\|Q|\|Z|\|N");
    }
  catch (const std::domain_error& e)
    {
      std::cerr << "Syntax error : " << e.what();
      std::cerr << "You may wanted to use |R, |Q, |Z or |N for variable type\n" << std::endl;
    }
}

// Check that the symbol is matched by the following
// regex : [a-zA-Z][a-zA-Z0-9]*
void Parser::symbol()
{
  std::regex sym("[a-zA-Z][a-zA-Z0-9]*");
  std::tuple<std::string, unsigned> r = get_next_word();
  std::string la = std::get<0>(r);
  unsigned off = std::get<1>(r);
  bool res = std::regex_match(la, sym);
  this->cur += off;
  if (!res)
    throw std::invalid_argument("The symbol pattern is not matching, expecting [a-zA-Z][a-zA-Z0-9]* received : " + la + "\n");
}

void Parser::parse()
{
  try
    {
      this->app();
    }
  catch(const std::invalid_argument& e)
    {
      std::cerr << "Syntax error : " << e.what() << std::endl;
    }
}
