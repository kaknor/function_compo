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
	  const std::string prompt = "-i";
	  if (prompt.compare(argv[1]))
	    {
	      for (int i = 1; i < argc; i++)
		{
		  Parser p = Parser(argv[i], false);
		  p.parse();
		}
	      return 0;
	    }
	  // Interactive mode is on.
	  std::cout << "Interactive mode is on\n";
	  std::cout << ">>> ";
	  std::string input;
	  while(std::getline(std::cin, input))
	    {
	      Parser p = Parser(input, true);
	      p.parse();
	      std::cout << ">>> ";
	    }
	  return 0;
	}
      catch(const std::invalid_argument& e)
      	{
      	  std::cerr << // this->cur.get_name() +
      	    " : Syntax error : " << e.what() << std::endl;
	  return 1;
      	}
      catch(const std::domain_error& e)
      	{
      	  std::cerr << // this->cur.get_name()
      	    + " : Syntax error : " << e.what() << std::endl;
	  return 1;
      	}
      catch(const std::exception& e)
      	{
      	  std::cerr << "Program error : " << e.what() << std::endl;
      	  return 1;
      	}
      catch(...)
      	{
      	  std::cerr << "Program error : Unexpected error\n" << std::endl;
	  return 1;
      	}
    }
}
