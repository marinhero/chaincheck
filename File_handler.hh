//
// File_handler.hh for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
//
// Made by Marin Alcaraz
// Login   <A01203109@itesm.mx>
//
// Started on  Thu Nov 07 16:58:28 2013 Marin Alcaraz
// Last update Thu Nov 07 19:44:44 2013 Marin Alcaraz
//

#ifndef FILE_HANDLER_HH_
# define FILE_HANDLER_HH_

#include <fstream> //implicit construction for _file

#define LINE_BY_LINE    1
#define BULK            2

class vector;
class string;
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

        void             open_file() throw();
        void             close_file();
};

std::ostream &operator<<(std::ostream& os, const File_handler&);

#endif /* END OF FILE_HANDLER_HH_ */
