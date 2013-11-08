//
// main.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 18:25:58 2013 Marin Alcaraz
// Last update Thu Nov 07 20:15:58 2013 Marin Alcaraz
//

#include <string>
#include <iostream>
#include <fstream>
#include "File_handler.hh"


int                 initializer(std::string grammar, std::string chains)
{
    File_handler    gf(grammar);
    File_handler    cf(grammar);
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

