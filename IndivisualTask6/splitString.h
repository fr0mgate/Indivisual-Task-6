#ifndef SPLIT_STRING_H
#define SPLIT_STRING_H

#include <string>
#include "Vector.h"

Vector<std::string> splitString(const std::string&, char = ' ');
Vector<std::string> splitString(const std::string&, const std::string&);

#endif // SPLIT_STRING_H
