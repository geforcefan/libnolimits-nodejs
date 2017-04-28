#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>


class Helper
{
public:
    static std::string leftTrim(std::string str);
    static std::string rightTrim(std::string str);
    static std::string trim(std::string str);
};

#endif // HELPER_H
