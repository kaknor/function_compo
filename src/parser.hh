#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Parser {

  std::string name;
  std::string content;
  std::string::iterator cur;

  std::string read_file();
  
public:
  Parser(std::string name): name(name)
  {
    content = read_file();
    cur = content.begin();
  }
  ~Parser(){};
  
  bool eat(std::string token);
};
