//
// File_handler.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 16:58:28 2013 Marin Alcaraz
// Last update Thu Nov 14 16:10:09 2013 Marin Alcaraz
//

#ifndef FILE_HANDLER_HH_
# define FILE_HANDLER_HH_

#include <fstream>
#include <string>
#include <vector>
#include <fstream>

class Exception;

class File_handler
{

    public:

        int             _status;
        std::string     const _file_name;
        std::ifstream   _file;

        File_handler(std::string);
        ~File_handler();
        File_handler(const File_handler &);
        File_handler operator=(const File_handler &);

};

std::ostream &operator<<(std::ostream& os, const File_handler&);

#endif /* END OF FILE_HANDLER_HH_ */
