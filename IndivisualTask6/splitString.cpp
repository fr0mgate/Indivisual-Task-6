#include "splitString.h"

Vector<std::string> splitString(const std::string& string, char divider) {
    Vector<std::string> stringsList;
    std::string temp;
    for (size_t i = 0; i < string.length(); i++) {
        if (string[i] == divider) {
            if (!temp.empty()) {
                stringsList.pushBack(temp);
                temp.clear();
            }
        }
        else
            temp.push_back(string[i]);
    }
    if (!temp.empty())
        stringsList.pushBack(temp);
    return stringsList;
}

Vector<std::string> splitString(const std::string& string, const std::string& dividers) {
    Vector<std::string> stringsList;
    std::string temp;
    bool isDivider = false;
    for (size_t i = 0; i < string.length(); i++) {
        for (size_t j = 0; j < dividers.length(); j++) {
            if (string[i] == dividers[j]) {
                isDivider = true;
                if (!temp.empty()) {
                    stringsList.pushBack(temp);
                    temp.clear();
                }
                break;
            }
        }
        if (!isDivider)
            temp.push_back(string[i]);
        isDivider = false;
    }
    if (!temp.empty())
        stringsList.pushBack(temp);
    return stringsList;
}
