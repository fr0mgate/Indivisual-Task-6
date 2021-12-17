#ifndef MY_STRING_H
#define MY_STRING_H

#include <ostream>
#include <cstddef>
#include <stdexcept>
#include "Vector.h"

class String
{
public:
    //String();
    String(String&);
    String(const char*);
    const String& operator= (const String&);
    ~String();

    [[nodiscard]] size_t size() const;
    void pushBack(char);
    void split(char = ' ');
    void split(const String&);

    char& operator[] (size_t);
    friend std::ostream& operator<< (std::ostream&, const String&);
    bool operator== (const String&);
    bool operator< (const String&);
    bool operator> (const String&);
    bool operator<= (const String&);
    bool operator>= (const String&);

private:
    Vector<char> charsArray_;
};

#endif // MY_STRING_H
