#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>

class Tape_reader
{
  const std::string *name;
  const std::string *content;
  std::string::const_iterator cur;
  bool is_prompt;
  unsigned column;
  unsigned line;

  void read_file();
  void incr();
  
public:

  Tape_reader(std::string name, bool is_prompt)
    try : is_prompt(is_prompt), column(0), line(0)
	    {
	      if (!is_prompt)
		{
		  this->name = new std::string(name);
		  this->read_file();
		}
	      else
		{
		  this->content = new std::string(name);
		}
	      this->cur = content->begin();
	    }
  catch(std::exception& e)
    {
      std::cerr << "Parse error : unexpected error with tape_reader construction" << e.what() << std::endl;
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
  const std::string &get_name() const;
  bool get_is_prompt() const;
};
