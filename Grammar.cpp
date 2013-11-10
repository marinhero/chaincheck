//
// Grammar.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:38:00 2013 Marin Alcaraz
// Last update Sat Nov 09 23:04:16 2013 Marin Alcaraz
//

#include <vector>
#include <string>
#include <iostream>
#include "Grammar.hh"

Grammar::Grammar(std::string name) : _name(name)
{
    std::cout << "[+] Constructor: Called Grammar constructor. "
            << " Grammar object initialized with name: " << _name << std::endl;
}

Grammar::~Grammar()
{
    std::cout <<"[+] Destructor: Called Grammar Destructor" << std::endl;
}

void Grammar::populate_grammar()
{

}
