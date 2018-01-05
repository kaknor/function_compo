#include <iostream>
#include "parser.hh"

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      std::cerr << "Bad usage : no file given\n" << std::endl;
      return 1;
    }
  else
    {
      try
      	{
	  for (int i = 1; i < argc; i++)
	    {
	      Parser p = Parser(argv[i]);
	      p.parse();
	    }
	  return 0;
	}
      catch(const std::exception& e)
      	{
      	  std::cerr << "Program error : " << e.what() << std::endl;
      	}
      catch(...)
      	{
      	  std::cerr << "Program error : Unexpected error\n" << std::endl;
      	}
    }
}
