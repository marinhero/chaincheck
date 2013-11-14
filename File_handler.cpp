//
// File_handler.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 16:57:09 2013 Marin Alcaraz
// Last update Thu Nov 14 16:21:54 2013 Marin Alcaraz
//

#include <iostream>
#include "File_handler.hh"
#include "Exception.hh"

File_handler::File_handler(std::string fn) : _file_name(fn), _status(0)
{
    std::cout <<"[+] Constructor: ";
    _file.open(_file_name);
    if (_file.is_open() == false)
        throw IOErrorException("[-] File_handler: Unable to open file: "
                + _file_name);
    _status = 1;
    std::cout << "[+] File Handler: opened file: "
        << _file_name << std::endl;
    std::cout << *this << std::endl;
}

File_handler::~File_handler()
{
    std::cout <<"[+] Destructor: ";
    _file.close();
    _status = 0;
    std::cout << *this << std::endl;
}

std::ostream        &operator<<(std::ostream& os, const File_handler &f)
{
    std::string     st;

    if (f._status == 0)
        st = "CLOSED";
    else
        st = "OPEN";
    std::cout << "[*] File Handler: Associated file: "
            << f._file_name << " status: [" <<
            st <<  "]";
    return (os);
}
