#ifndef DATA_VECTOR_H
#define DATA_VECTOR_H

#include <ostream>
#include <cstddef>
#include <stdexcept>

template<typename T>
class Vector;

template<typename T>
std::ostream& operator<< (std::ostream&, const Vector<T>&);

template<typename T>
class Vector
{

public:
    Vector();
    Vector(Vector&);
    Vector(Vector&&) noexcept;
    const Vector& operator= (const Vector&);
    const Vector& operator=(Vector&&) noexcept;
    ~Vector();

    [[nodiscard]] size_t size() const;
    void pushBack(const T&);
    void selectionSort();

    T& operator[] (size_t);
    friend std::ostream& operator<< <T>(std::ostream&, const Vector&);
    bool operator== (const Vector&);
    bool operator< (const Vector&);
    bool operator> (const Vector&);
    bool operator<= (const Vector&);
    bool operator>= (const Vector&);

private:
    void addMemory();

    T* array_;
    size_t size_;
    size_t capacity_;
};

#endif // DATA_VECTOR_H
