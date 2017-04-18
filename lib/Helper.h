#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string.h>

class Helper
{
public:
    static std::string leftTrim(std::string str);
    static std::string rightTrim(std::string str);
    static std::string trim(std::string str);
};

#endif // HELPER_H
