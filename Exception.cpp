//
// Exception.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 17:35:05 2013 Marin Alcaraz
// Last update Thu Nov 07 18:36:17 2013 Marin Alcaraz
//

#include <string>
#include "Exception.hh"

Exception::Exception(const std::string & msg) throw() : _what(msg)
{

}

Exception::~Exception(void) throw()
{}

const char        *Exception::what(void) const throw()
{
      return (this->_what.data());
}

IOErrorException::IOErrorException(std::string const &msg) throw(): Exception(msg)
{
}

IOErrorException::~IOErrorException() throw()
{
}

UndefinedSymbolException::UndefinedSymbolException(std::string const &msg)
throw(): Exception(msg)
{
}

UndefinedSymbolException::~UndefinedSymbolException() throw()
{
}
