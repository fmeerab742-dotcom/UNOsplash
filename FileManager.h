#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
    static bool saveUser(const std::string& username,
                         const std::string& password);

    static bool validateUser(const std::string& username,
                             const std::string& password);

    static bool userExists(const std::string& username);
};

#endif