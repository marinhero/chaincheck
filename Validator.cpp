//
// Validator.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Fri Nov 15 10:14:36 2013 Marin Alcaraz
// Last update Fri Nov 15 11:05:15 2013 Marin Alcaraz
//

#include <iostream>
#include "Validator.hh"
#include "Grammar.hh"
#include "File_handler.hh"

Validator::Validator(std::string n) : _name(n)
{
    std::cout << "[+] Constructori: Validator Object initialized"
        " with name: " << _name << std::endl;
}

Validator::~Validator()
{

}

void Validator::verify(Grammar &g, File_handler &chains)
{
    std::string     line;

    std::cout << "To check Grammar[" << g._name << "] "
        " with  file: "  << chains._file_name << std::endl;
    _substack.push(g._rules.find("S")->second);
    while (chains._file >> line)
    {
        std::cout << "Chain to check[" << line << "]" <<std::endl;
    }
}
