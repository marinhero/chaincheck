//
// Grammar.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:47:26 2013 Marin Alcaraz
// Last update Thu Nov 14 20:27:06 2013 Marin Alcaraz
//

#ifndef GRAMMAR_HH_
# define GRAMMAR_HH_

#include <map>
#include <string>
#include <vector>

class Grammar
{
    public:
        std::string                                 _name;
        std::multimap<std::string, std::string>     _rules;
        std::vector<std::string>                    _terminals;
        std::vector<std::string>                    _nonterminals;

        Grammar(std::string);
        ~Grammar();
        Grammar(const Grammar &);
        Grammar operator=(const Grammar &);

        void push_back(std::string, std::string);
};

std::ostream    &operator<<(std::ostream& os, Grammar &g);

#endif /* END OF GRAMMAR */
