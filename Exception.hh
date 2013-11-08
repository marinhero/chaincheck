/*
** Exception.h for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
**
** Made by Marin Alcaraz
** Login   <A01203109@itesm.mx>
**
** Started on  Thu Nov 07 17:35:40 2013 Marin Alcaraz
** Last update Thu Nov 07 17:38:02 2013 Marin Alcaraz
*/

#ifndef EXCEPTION_HH_
# define EXCEPTION_HH_

class string;
class exception;

class        Exception : public std::exception
{
    protected:
        std::string        _what;

    public:
        Exception(std::string const &error) throw();
        virtual const char *what(void) const throw();
        virtual ~Exception(void) throw();
};

class                IOErrorException : public Exception
{
    public:
        IOErrorException(std::string const &error) throw();
        virtual ~IOErrorException() throw();
};

class                UndefinedSymbolException : public Exception
{
    public:
        UndefinedSymbolException(std::string const &error) throw();
        virtual ~UndefinedSymbolException() throw();
};

#endif /* !EXCEPTION_HH_ */
