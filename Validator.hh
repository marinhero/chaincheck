//
// Validator.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Fri Nov 15 10:12:41 2013 Marin Alcaraz
// Last update Fri Nov 15 11:03:50 2013 Marin Alcaraz
//

#ifndef VALIDATOR_HH_
# define VALIDATOR_HH_

#include <string>
#include <stack>

class Grammar;
class File_handler;

class Validator
{
    public:
        std::string                         _name;
        std::stack<std::string>             _substack;

        Validator(std::string);
        ~Validator();
        Validator(const Validator &);
        Validator &operator=(const Validator &);

        void verify(Grammar &g, File_handler &chains);
};

#endif /* !VALIDATOR_HH_ */
