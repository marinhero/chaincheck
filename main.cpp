//
// main.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 18:25:58 2013 Marin Alcaraz
// Last update Thu Nov 14 20:26:40 2013 Marin Alcaraz
//

#include <string>
#include <iostream>
#include <fstream>
#include "Grammar.hh"
#include "File_handler.hh"
#include "Parser.hh"


int                 initializer(std::string grammar, std::string chains)
{
    File_handler    grammar_file(grammar);
    File_handler    chain_file(chains);
    Grammar         my_grammar("My_grammar");
    Parser          my_parser("My_parser");

    my_parser.parse_grammar(my_grammar, grammar_file);
    std::cout << my_grammar << std::endl;
    return (0);
}

int                 main(int argc, char **av)
{
    std::string     grammar_file;
    std::string     chains_file;

    if (argc == 3)
    {
        grammar_file    =  av[1];
        chains_file     =  av[2];
        initializer(grammar_file, chains_file);
    }
    else
    {
        std::cout << "Usage: ./chain_checker grammar_file chains_file" << std::endl;
        return (0);
    }
}

