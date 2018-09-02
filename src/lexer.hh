#pragma once

#include <string>
#include <fstream>
#include <iostream>

class Lexer
{
  Lexer(){};
  ~Lexer(){};

  static bool eat(std::string *content, std::string::iterator *cur, std::string token);
};
