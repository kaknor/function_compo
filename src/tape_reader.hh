#pragma once

#include <string>

class tape_reader
{
  std::string content;
  std::string::iterator cur;
  unsigned column;
  unsigned line;

public:
  //++ += =
  std::string operator=(std::string s)
  {
    this->content = s;
    return this->content;
  }

  std::string::iterator operator=(std::string::iterator i)
  {
    this->cur = i;
    return this->cur;
  }

  std::string::iterator operator++()
  {
    return this->cur++;
  }

  std::string::iterator operator +=(unsigned n)
  {
    return this->cur += n;
  }

  std::string::iterator operator +=(int n)
  {
    return this->cur += n;
  }

  operator std::string()
  {
    return this->content;
  }
  
  operator std::string::iterator()
  {
    return this->cur;
  }
};
