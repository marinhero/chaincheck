//
// Grammar.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:38:00 2013 Marin Alcaraz
// Last update Fri Nov 15 09:28:24 2013 Marin Alcaraz
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
    else if (v_name == "nonterminals")
        this->_nonterminals.push_back(token);
    else
        std::cout << "[!] Warning: No vector called: " << v_name
            << " in Grammar: " << this->_name << " was found ";
}

std::ostream    &operator<<(std::ostream& os, Grammar &g)
{
    std::vector<std::string>::iterator              it;
    std::map<std::string, std::string>::iterator    iter;
    std::string                                     map_val;

    std::cout << "/***** GRAMMAR INFORMATION *****\\" << std::endl;
    std::cout << "[*] TERMINALS: " << std::endl;
    for (it = g._terminals.begin() ; it != g._terminals.end() ; ++it)
        std::cout << *it << std::endl;
    std::cout << "[*] NON_TERMINALS: " << std::endl;
    for (it = g._nonterminals.begin() ; it != g._nonterminals.end() ; ++it)
        std::cout << *it << std::endl;
    std::cout << "[*] PRODUCTIONS: " << std::endl;
    for (iter = g._rules.begin(); iter != g._rules.end(); ++iter)
    {
        map_val.append(iter->first); //Not a method call
        map_val.append("=");
        map_val.append(iter->second);
        std::cout << map_val << std::endl;
        map_val = "";
    }
    std::cout << "/***** END OF GRAMMAR INFORMATION *****\\";
    return (os);
}
