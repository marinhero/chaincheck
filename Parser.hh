//
// Parser.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:47:28 2013 Marin Alcaraz
// Last update Thu Nov 14 16:53:07 2013 Marin Alcaraz
//

#ifndef PARSER_HH_
# define PARSER_HH_

#include <stack>
#include <map>
#include <vector>
#include <string>

class Grammar;
class File_handler;

class Parser
{
    public:

        std::string                 _name;
        std::stack<std::string>     _parsing_sequence;
        std::vector<int>            _subs_sequence;

        Parser(std::string);
        ~Parser();

        void                        parse_grammar(Grammar &g,
                                        File_handler &f);
        void                        tokenizer(std::string,
                                        Grammar &grammar, std::string);
};

#endif /* !PARSER_HH_ */
