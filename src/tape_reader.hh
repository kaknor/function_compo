#pragma once

class tape_reader
{
  std::string content;
  std::string::iterator cur;
  unsigned column;
  unsigned line;

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

  
};
