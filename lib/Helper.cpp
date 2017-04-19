#include "Helper.h"

std::string Helper::leftTrim(std::string str) {
    int numStartSpaces = 0;
    for (unsigned long i = 0; i < str.length(); i++) {
        if (!isspace(str[i])) break;
        numStartSpaces++;
    }
    return str.substr(numStartSpaces);
}

std::string Helper::rightTrim(std::string str) {
    int numEndSpaces = 0;
    for (long i = str.length() - 1; i >= 0; i--) {
        if (!isspace(str[i])) break;
        numEndSpaces++;
    }
    return str.substr(0, str.length() - numEndSpaces);
}
std::string Helper::trim(std::string str) {
    return Helper::rightTrim(Helper::leftTrim(str));
}
