//
// main.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 18:25:58 2013 Marin Alcaraz
// Last update Mon Nov 18 15:37:52 2013 Marin Alcaraz
//

#include <string>
#include <iostream>
#include <fstream>
#include "Grammar.hh"
#include "File_handler.hh"
#include "Parser.hh"
#include "Validator.hh"


int                 initializer(Grammar &my_grammar, std::string grammar)
{
    File_handler    grammar_file(grammar);
    Parser          my_parser("My_parser");

    my_parser.parse_grammar(my_grammar, grammar_file);
    std::cout << my_grammar << std::endl;
    return (0);
}

int                 validate_grammar(Grammar &g, std::string const chains)
{
    Validator       v("My_validator");
    File_handler    chain_file(chains);

    v.verify(g, chain_file);
    return (0);
}

int                 main(int argc, char **av)
{
    std::string     grammar_file;
    std::string     chains_file;
    Grammar         my_grammar("My_grammar");

    if (argc == 3)
    {
        grammar_file    =  av[1];
        chains_file     =  av[2];
        initializer(my_grammar, grammar_file);
        validate_grammar(my_grammar, chains_file);
    }
    else
    {
        std::cout << "Usage: ./chain_checker grammar_file chains_file" << std::endl;
        return (0);
    }
}

