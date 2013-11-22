//
// Parser.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Sat Nov 09 22:43:20 2013 Marin Alcaraz
// Last update Fri Nov 22 00:05:59 2013 Marin Alcaraz
//

#include <iostream>
#include <fstream>
#include "Parser.hh"
#include "Grammar.hh"
#include "File_handler.hh"

#define     DELIMITER ','

Parser::Parser(std::string n) : _name(n)
{
}

Parser::~Parser()
{
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
        grammar.push_back(token, v_name);
        line.erase(0, pos + delimiter.length());
        if (line.find(delimiter) == std::string::npos)
        {
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
        value = line.substr(0 , line.find("|"));
        value = value.substr(value.find(",") + 1);
        grammar._rules.insert(
                std::pair<std::string, std::string>(key, value));
        line = line.substr(line.find("|") + 1);
        aux = key + "," + line;
        rule_builder(aux, grammar); //Recursive call
    }
    else
    {
        value = line.substr(pos + 1);
        grammar._rules.insert(std::pair<std::string, std::string>(key, value));
    }
}

void                Parser::parse_grammar(Grammar &grammar,
                                File_handler &file)
{
    std::string     line;

    while (file._file >> line)
    {
        if (line.compare(0, 10, "terminales") == 0)
            this->tokenizer(line.substr(line.find("=") + 1), grammar,
                    "terminals");
        else if (line.compare(0, 12, "noterminales") == 0)
            this->tokenizer(line.substr(line.find("=") + 1), grammar,
                    "nonterminals");
        else
            rule_builder(line, grammar);
    }
}
