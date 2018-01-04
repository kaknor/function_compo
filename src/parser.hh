#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <regex>
#include <exception>

class Parser {

  std::string name;
  std::string content;
  // TODO : classe pour gere les lignes et colonnes du fichier
  std::string::iterator cur;

  std::string read_file();

  // TOOLBOX functions
  std::tuple<std::string, unsigned> get_next_word();
  std::string lookahead();
  // TODO : classe pour gere propement
  // les tokens simple et les regex
  void eat(std::string token);

  // grammar functions
  void app();
  void list();
  void ens();
  void symbol();
  
public:
  Parser(std::string name): name(name)
  {
    content = read_file();
    cur = content.begin();
  }
  ~Parser(){};

  void parse();

};
