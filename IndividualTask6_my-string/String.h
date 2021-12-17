#ifndef MY_STRING_H
#define MY_STRING_H

#include <istream>
#include <ostream>
#include <cstddef>

class String
{
public:
    String();
    String(const String&);
    String(const char*);
    const String& operator= (const String&);
    const String& operator= (const char*);

    [[nodiscard]] size_t length() const;
    [[nodiscard]] bool empty() const;
    void pushBack(char);
    void clear();
    const char* toCharsArray();
    String substr(size_t, size_t);
    Vector<String> split(char = ' ');
    Vector<String> split(const String&);

    char& operator[] (size_t);
    char& operator[] (size_t) const;
    friend std::istream& operator>> (std::istream&, String&);
    friend std::ostream& operator<< (std::ostream&, const String&);
    bool operator== (const String&);
    bool operator!= (const String&);
    bool operator< (const String&);
    bool operator> (const String&);
    bool operator<= (const String&);
    bool operator>= (const String&);

private:
    Vector<char> charsVector_;
    static const size_t LIMIT = 80;
};

#endif // MY_STRING_H
