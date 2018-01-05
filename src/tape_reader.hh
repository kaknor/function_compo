#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <memory>

class Tape_reader
{
  const std::string &name;
  const std::string *content;
  std::string::const_iterator cur;
  unsigned column;
  unsigned line;

  void read_file();
  
public:

  Tape_reader(std::string name) : name(name), column(0), line(0)
  {
    this->read_file();
    this->cur = content->begin();
  }

  ~Tape_reader()
  {
    delete this->content;
  };

  std::string::const_iterator operator++();
  std::string::const_iterator operator +=(unsigned n);
  std::string::const_iterator operator +=(int n);
  const std::string &get_content() const;
  std::string::const_iterator get_cur() const;
};
