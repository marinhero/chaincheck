//
// Parser.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:43:20 2013 Marin Alcaraz
// Last update Thu Nov 14 17:09:10 2013 Marin Alcaraz
//

#include <iostream>
#include <fstream>
#include "Parser.hh"
#include "Grammar.hh"
#include "File_handler.hh"

#define     DELIMITER ','

Parser::Parser(std::string n) : _name(n)
{
    std::cout << "[+] Constructor: Called Parser constructor. "
            << " Parser object initialized with name: " << _name <<
            std::endl;
}

Parser::~Parser()
{
    std::cout <<"[+] Destructor: Called Parser Destructor" << std::endl;
}

void        Parser::tokenizer(std::string line, Grammar &grammar,
                    std::string v_name)
{
    int             pos;
    std::string     token;
    std::string     delimiter;

    delimiter = DELIMITER;
    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
        std::cout << "Parsing: " << token << std::endl;
        grammar.push_back(token, v_name);
        line.erase(0, pos + delimiter.length());
        if (line.find(delimiter) == std::string::npos)
        {
            std::cout << "Parsing: " << line.substr(pos - 1) << std::endl;
            token = line.substr(pos - 1);
            grammar.push_back(token, v_name);
            return ;
        }
    }
}

void    Parser::parse_grammar(Grammar &grammar,
                            File_handler &file)
{
    std::string     line;

    while (file._file >> line)
    {
        std::cout << "line: [" << line << "]"
            << std::endl;
        if (line.compare(0, 10, "terminales") == 0)
        {
            std::cout << "TERMINAL TAG DETECTED" << std::endl;
            this->tokenizer(line.substr(line.find("=") + 1), grammar, "terminals");
        }
        if (line.compare(0, 12, "noterminales") == 0)
        {
            std::cout << "NONTERMINAL TAG DETECTED" << std::endl;
            this->tokenizer(line.substr(line.find("=") + 1), grammar, "nonterminals");
        }
    }
}
