#include "tape_reader.hh"

// Read the file (named name), and return the content in a string
void Tape_reader::read_file()
{
  std::ifstream file(this->name);
  if (!file.good())
    throw std::invalid_argument("The file : "+ this->name +" cannot be open\n");
  std::stringstream buff;
  buff << file.rdbuf();
  this->content = new std::string(buff.str());
}

std::string::const_iterator Tape_reader::operator++()
{
  return this->cur++;
}

std::string::const_iterator Tape_reader::operator +=(unsigned n)
{
  return this->cur += n;
}

std::string::const_iterator Tape_reader::operator +=(int n)
{
  return this->cur += n;
}
  
const std::string &Tape_reader::get_content() const
{
  return *this->content;
}
  
std::string::const_iterator Tape_reader::get_cur() const
{
  return this->cur;
}
