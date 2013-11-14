//
// Grammar.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:38:00 2013 Marin Alcaraz
// Last update Thu Nov 14 16:51:24 2013 Marin Alcaraz
//

#include <iostream>
#include "Grammar.hh"
#include "Parser.hh"

Grammar::Grammar(std::string name) : _name(name)
{
    std::cout << "[+] Constructor: Called Grammar constructor. "
            << " Grammar object initialized with name: " << _name << std::endl;
}

Grammar::~Grammar()
{
    std::cout <<"[+] Destructor: Called Grammar Destructor" << std::endl;
}

void Grammar::push_back(std::string token, std::string v_name)
{
    if (v_name == "terminals")
        this->_terminals.push_back(token);
    if (v_name == "nonterminals")
        this->_nonterminals.push_back(token);
}
