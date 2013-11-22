//
// Validator.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <marin.alcaraz@gmail.com>
//
// Started on  Fri Nov 15 10:14:36 2013 Marin Alcaraz
// Last update Fri Nov 22 00:22:46 2013 Marin Alcaraz
//

#include <iostream>
#include <sstream>
#include "Validator.hh"
#include "Grammar.hh"
#include "File_handler.hh"

#define  END_SYMBOL "$"

Validator::Validator(std::string n) : _name(n)
{
    std::string end_symbol;

    end_symbol = END_SYMBOL;
    _substack.push(end_symbol);
    _derivation = "";
}

Validator::~Validator()
{
}

void Validator::show_stack()
{
    for (std::stack<std::string> dump = _substack; !dump.empty(); dump.pop())
        std::cout << dump.top() << ",";
    std::cout << std::endl;
}

bool Validator::verify_alphabet(Grammar  &g, std::string chain)
{
   int          i;
   std::string  current_token;

   for (i = 0; chain[i] != '\0'; i++)
   {
        current_token = chain[i];
        if (!(g.contains(current_token)))
            return (false); //Exception here
   }
   return (true);
}

std::string Validator::get_rule(Grammar &g, std::string current, std::string predict)
{
    std::string     key;
    std::pair<std::multimap<std::string, std::string>::iterator,
        std::multimap<std::string, std::string>::iterator> range;
    std::multimap<std::string, std::string>::iterator it;

    key = g.get_key(current, predict);
    range = g._rules.equal_range(key);
    it = range.first;
    for (; it != range.second; ++it)
    {
        if (g.contains_nonterm(it->second) == false
                && it->second == current
                && it->first == _substack.top()
                && current != predict)
            return (it->second);
        else if (g.contains_nonterm(it->second) == true
                && it->first == _substack.top()
                && current == predict)
                return (it->second);

    }
    return ("NO-RULE");
}

bool Validator::rule_handler(Grammar &g, std::string const &current_token,
            std::string const &prediction_token)
{
    std::string     rule;

    rule = get_rule(g, current_token, prediction_token);
    if (rule != "NO-RULE")
    {
        _substack.pop();
        token_push(rule);
    }
    else
        return (false);
    return (true);
}

bool Validator::stack_validator(Grammar &g, std::string const &current_token,
        std::string const &prediction_token)
{
    if (g.contains_nonterm(_substack.top()))
    {
        if (!rule_handler(g, current_token, prediction_token))
            return (false);
    }
    if (current_token == _substack.top())
        _substack.pop();
    else
        return (false);
    return (true);
}

bool Validator::verify_chain(Grammar &g, std::string chain)
{
    int             i;
    std::string     current_token;
    std::string     prediction_token;

    i = 0;
    while (chain[i] != '\0')
    {
        current_token = chain.at(i);
        try
        { prediction_token = chain.at(i + 1); }
        catch (std::exception &e)
        { prediction_token = ""; }
        if (!stack_validator(g, current_token, prediction_token))
            return (false);
        i = i + 1;
    }
    if (_substack.top() == "$")
        return (true);
    return (false);
}

void Validator::token_push(std::string rule)
{
    int i;

    i = rule.length() - 1;
    _derivation.append("-" + rule);
    while (i >= 0)
    {
        std::string str;
        str = rule.at(i);
        _substack.push(str);
        i = i - 1;
    }
}

void Validator::clearsubstack(Grammar &g)
{
    std::string initial_rule;

    while (_substack.top() != "$")
        _substack.pop();
    initial_rule = g._rules.find("S")->second;
    token_push(initial_rule);
    _derivation = g._rules.find("S")->second;
}

void Validator::log_result(Grammar &g, std::string line)
{
    std::stringstream       outline_stream;
    File_handler            output("output.txt");

    if (verify_chain(g, line))
    {
        outline_stream << "[+] CHAIN ACCEPTED BY GRAMMAR" << std::endl;
        std::cout << outline_stream.str();
        output.save_string(outline_stream);
        outline_stream << "Arbol binario[in-order]: " << _derivation << std::endl;
        std::cout << outline_stream.str();
        output.save_string(outline_stream);
        _derivation = "";
    }
    else
    {
        outline_stream << "[-] CHAIN REJECTED BY GRAMMAR" << std::endl;
        std::cout << outline_stream.str();
        output.save_string(outline_stream);
    }
    clearsubstack(g);
}

void Validator::verify(Grammar &g, File_handler &chains)
{
    File_handler            output("output.txt");
    std::string             line;
    std::stringstream       outline_stream;

    clearsubstack(g);
    while (chains._file >> line)
    {
        outline_stream << "[+] Validator: chain [" << line << "]" << std::endl;
        std::cout << outline_stream.str();
        output.save_string(outline_stream);
        if (verify_alphabet(g, line))
            log_result(g, line);
        else
        {
            outline_stream << "[-] Error: invalid chain, "
                "undefined symbols on the string" << std::endl;
            std::cout << outline_stream.str();
            output.save_string(outline_stream);
        }
    }
    outline_stream << "-------------------END OF RUN----------------"
        << std::endl;
    output.save_string(outline_stream);
}
