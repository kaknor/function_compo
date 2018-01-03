#pragma once

#include <string>
#include <fstream>
#include <iostream>

class Parser {

  std::string file;

public:
  Parser(std::string file): file(file) {}
  ~Parser(){};
  
  void read_file();
};
