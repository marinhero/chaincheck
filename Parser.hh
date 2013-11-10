//
// Parser.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:47:28 2013 Marin Alcaraz
// Last update Sat Nov 09 23:13:50 2013 Marin Alcaraz
//

#ifndef PARSER_HH_
# define PARSER_HH_

class map;
class vector;
class stack;
class Grammar;

class Parser
{
    public:

        std::string         _name;
        std::stack<std::string>  _parsing_sequence;
        std::vector<int>    _subs_sequence;

        Parser(std::string);
        ~Parser();

        void                parse_grammar(Grammar &g);
};

#endif /* !PARSER_HH_ */
