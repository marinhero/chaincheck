//
// Grammar.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 21:38:00 2013 Marin Alcaraz
// Last update Thu Nov 21 01:45:00 2013 Marin Alcaraz
//
/*
    Grammar.cpp se encarga de preparar la gramática para que pueda ser usada en el mapeo y hacer uso de otras librerías:
    Descripción de Métodos:
    - Constructor y Destructur
    - Agregación de símbolos terminales y no terminales al stack usando un token y un vector (v_name)
    - Búsqueda de símbolos terminales y no terminales.
    - Obtención del "key" para el multimapeo.
    - Sobecarga de operadores para el despliegue de los componentes de la gramática (símbolos terminales y SNTs).
*/

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

bool Grammar::contains(std::string token)
{
    std::vector<std::string>::iterator it;

    for (it = _terminals.begin(); it != _terminals.end(); it++)
    {
        if (*it == token)
            return (true);
    }
    return (false);
}

bool Grammar::contains_nonterm(std::string token)
{
    std::vector<std::string>::iterator it;

    for (it = _nonterminals.begin(); it != _nonterminals.end(); it++)
    {
        if (token.find(*it) != std::string::npos)
            return (true);
    }
    return (false);
}

std::string     Grammar::get_key(std::string current,  std::string predict)
{
    std::multimap<std::string, std::string>::iterator it;

    it = _rules.begin();
    while (it != _rules.end())
    {
        if ((it->second).find(current) != std::string::npos)
            return (it->first);
        ++it;
    }
    return ("NULL");
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
