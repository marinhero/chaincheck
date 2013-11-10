//
// Grammar.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:47:26 2013 Marin Alcaraz
// Last update Sat Nov 09 23:06:35 2013 Marin Alcaraz
//

#ifndef GRAMMAR_HH_
# define GRAMMAR_HH_

class vector;
class map;
class string;
class Exception;

#include <iostream>
#include <map>


class Grammar
{
    public:
        std::string                 _name;
        std::map<std::string, int>  _rules;
        std::vector<char>           _terminals;
        std::vector<char>           _nonterminals;

        Grammar(std::string);
        ~Grammar();
        Grammar(const Grammar &);
        Grammar operator=(const Grammar &);

        void                        populate_grammar();
};

#endif /* END OF GRAMMAR */
