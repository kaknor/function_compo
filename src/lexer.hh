#pragma once

#include <string>
#include <fstream>
#include <iostream>

class Lexer
{
  // TODO : faire un tableau avec les sperateurs
  // ie : \t \n \s etc...
public:
  Lexer(){};
  ~Lexer(){};

  static bool eat(std::string *content, std::string::iterator *cur, std::string token);
};
