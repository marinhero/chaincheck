//
// Parser.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:43:20 2013 Marin Alcaraz
// Last update Thu Nov 14 19:54:47 2013 Marin Alcaraz
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

void                Parser::rule_builder(std::string line, Grammar &grammar)
{
    int             pos;
    char            delimiter;
    std::string     key;
    std::string     value;
    std::string     aux;

    delimiter = DELIMITER;
    pos = line.find(delimiter);
    key = line[pos - 1];
    if (line.find("|") != std::string::npos)
    {
        std::cout << "MULTIPLE RULE PRODUCTION DETECTED" << std::endl;
        value = line.substr(0 , line.find("|"));
        value = value.substr(value.find(",") + 1);
        grammar._rules.insert(
                std::pair<std::string, std::string>(key, value));
        std::cout << "Recursive Parsing: key[" << key << "] value[" <<
        value <<  "]" <<std::endl;
        line = line.substr(line.find("|") + 1);
        aux = key + "," + line;
        std::cout << "next str [" << aux << "]" << std::endl;
        rule_builder(aux, grammar); //Recursive call
    }
    else
    {
        value = line.substr(pos + 1);
        std::cout << "Parsing: key[" << key
            << "] value[" << value << "]"<< std::endl;
        grammar._rules.insert(std::pair<std::string, std::string>(key, value));
    }
    std::cout << line << std::endl;
}

void                Parser::parse_grammar(Grammar &grammar,
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
            this->tokenizer(line.substr(line.find("=") + 1), grammar,
                    "terminals");
        }
        else if (line.compare(0, 12, "noterminales") == 0)
        {
            std::cout << "NONTERMINAL TAG DETECTED" << std::endl;
            this->tokenizer(line.substr(line.find("=") + 1), grammar,
                    "nonterminals");
        }
        else
        {
            std::cout << "GRAMMAR SECTION DETECTED"  << std::endl;
            rule_builder(line, grammar);
        }

    }
}
