#pragma once

#include "tape_reader.hh"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <regex>
#include <exception>
#include <memory>

class Parser {

  // TODO : classe pour gere les lignes et colonnes du fichier
  Tape_reader cur;

  // TOOLBOX functions
  std::tuple<std::string, unsigned> get_next_word();
  std::string lookahead();
  // TODO : classe pour gerer propement
  // les tokens simples et les regex
  void eat(std::string token);

  // grammar functions
  void dec();
  void app();
  void list();
  void ens();
  void symbol();
  
public:
  //on appel le constructeur de cur de base sinon ca fait une copie et ca casse tout
  Parser(std::string name) : cur(name){}
  
  ~Parser(){};

  void parse();

};
