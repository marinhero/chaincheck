//
// Parser.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:43:20 2013 Marin Alcaraz
// Last update Sat Nov 09 23:10:33 2013 Marin Alcaraz
//

#include <map>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "Parser.hh"
#include "Grammar.hh"

Parser::Parser(std::string n) : _name(n)
{
    std::cout << "[+] Constructor: Called Parser constructor. "
            << " Parser object initialized with name: " << _name;
}

Parser::~Parser()
{
    std::cout <<"[+] Destructor: Called Parser Destructor" << std::endl;
}

void    Parser::parse_grammar(Grammar &g)
{

}
