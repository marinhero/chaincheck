// Validator.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Started on  Fri Nov 15 10:12:41 2013 Marin Alcaraz
// Last update Thu Nov 21 22:04:27 2013 Marin Alcaraz
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

        bool            verify_alphabet(Grammar &g, std::string);
        bool            verify_chain(Grammar &g, std::string);
        void            verify(Grammar &g, File_handler &chains);
        void            clearsubstack(Grammar &g);
        void            show_stack();
        void            token_push(std::string rule);
        std::string     get_rule(Grammar &, std::string, std::string);
        bool            rule_handler(Grammar &g, std::string const &,
                            std::string const &);
        bool            stack_validator(Grammar &g, std::string const &,
                            std::string const &);
};

#endif /* !VALIDATOR_HH_ */
