#include "tape_reader.hh"

// TODO : Replace strings with stream.
// Read the file (named name), and return the content in a string
void Tape_reader::read_file()
{
  const std::string &name = this->get_name();
  std::ifstream file(name);
  if (!file.good())
    throw std::invalid_argument("The file : "+ name +" cannot be open\n");
  std::stringstream buff;
  buff << file.rdbuf();
  this->content = new std::string(buff.str());
}

void Tape_reader::incr()
{
  if (*this->cur == '\n')
    {
      this->line++;
      this->column = 0;
    }
  else
    this->column++;
  this->cur++;
}

std::string::const_iterator Tape_reader::operator++()
{
  incr();
  return this->cur;
} 

std::string::const_iterator Tape_reader::operator +=(unsigned n)
{
  for (unsigned i = 0; i < n; i++)
    incr();
  return this->cur;
}

std::string::const_iterator Tape_reader::operator +=(int n)
{
  for (int i = 0; i < n; i++)
    incr();
  return this->cur;
}
  
const std::string &Tape_reader::get_content() const
{
  return *this->content;
}
  
std::string::const_iterator Tape_reader::get_cur() const
{
  return this->cur;
}

const std::string &Tape_reader::get_name() const
{
  return *this->name;
}
