//
// Grammar.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:47:26 2013 Marin Alcaraz
// Last update Thu Nov 14 16:49:14 2013 Marin Alcaraz
//

#ifndef GRAMMAR_HH_
# define GRAMMAR_HH_

#include <map>
#include <string>
#include <vector>

class Grammar
{
    public:
        std::string                         _name;
        std::map<std::string, int>          _rules;
        std::vector<std::string>            _terminals;
        std::vector<std::string>            _nonterminals;

        Grammar(std::string);
        ~Grammar();
        Grammar(const Grammar &);
        Grammar operator=(const Grammar &);

        void push_back(std::string, std::string);
};

#endif /* END OF GRAMMAR */
