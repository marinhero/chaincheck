//
// File_handler.cpp for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 16:57:09 2013 Marin Alcaraz
// Last update Fri Nov 22 02:09:15 2013 Marin Alcaraz
//

/*
    File_handler permite manejar de manera práctica los archivos de entrada. El constructor y destructor se imprimen en pantalla para que pueda corroborarse
    que el archivo se abrió y cerró correctamente. La sobrecarga de operador...
*/

#include <iostream>
#include <sstream>
#include "File_handler.hh"
#include "Exception.hh"

File_handler::File_handler(std::string fn) : _file_name(fn), _status(0)
{
    _file.open(_file_name.c_str());
    if (_file.is_open() == false)
        throw IOErrorException("[-] File_handler: Unable to open file: "
                + _file_name);
    _status = 1;
}

File_handler::~File_handler()
{
    _file.close();
    _status = 0;
}

void File_handler::save_string(std::stringstream &input)
{
    std::ofstream output_file;

    try
    {
        output_file.open(_file_name, std::fstream::app | std::fstream::out);
    }
    catch(std::exception &e)
    {
        std::cout << "Error openning file" << std::endl;
    }
    output_file << input.str();
    output_file.close();
    input.clear();
    input.str(std::string());
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
