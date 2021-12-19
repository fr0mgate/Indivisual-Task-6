#ifndef DATA_VECTOR_H
#define DATA_VECTOR_H

#include <ostream>
#include <cstddef>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Vector;

template<typename T>
std::ostream& operator<< (std::ostream&, const Vector<T>&);

template<typename T>
class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(Vector&&) noexcept;
    const Vector& operator= (const Vector&);
    const Vector& operator=(Vector&&) noexcept;
    ~Vector();

    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    void pushBack(const T&);
    void clear();
    void selectionSort();

    T& operator[] (size_t);
    T& operator[] (size_t) const;
    friend std::ostream& operator<< <T>(std::ostream&, const Vector&);
    bool operator== (const Vector&);
    bool operator!= (const Vector&);
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

template<typename T>
Vector<T>::Vector() :
	size_(0),
	capacity_(1)
{
	array_ = new T[capacity_];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) :
	size_(other.size_),
	capacity_(other.capacity_)
{
	array_ = new T[capacity_];
	for (size_t i = 0; i < size_; i++)
		array_[i] = other.array_[i];
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		other.array_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}
}

template<typename T>
const Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
	if (this != &other) {
		if (capacity_ != other.capacity_) {
			delete[] array_;
			capacity_ = other.capacity_;
			array_ = new T[capacity_];
		}
		size_ = other.size_;
		for (size_t i = 0; i < size_; i++)
			array_[i] = other.array_[i];
	}
	return *this;
}

template<typename T>
const Vector<T>& Vector<T>::operator= (Vector<T>&& other) noexcept
{
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		other.array_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] array_;
}

template<typename T>
void Vector<T>::addMemory()
{
	capacity_ *= 2;
	T* tempArray = array_;
	array_ = new T[capacity_];
	for (size_t i = 0; i < size_; i++)
		array_[i] = tempArray[i];
	delete[] tempArray;
}

template<typename T>
[[nodiscard]] size_t Vector<T>::size() const
{
	return size_;
}

template<typename T>
[[nodiscard]] bool Vector<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
void Vector<T>::pushBack(const T& element)
{
	if (size_ >= capacity_)
		addMemory();
	array_[size_++] = element;
}

template<typename T>
void Vector<T>::clear()
{
	size_ = 0;
	capacity_ = 1;
	delete[] array_;
	array_ = new T[capacity_];
}

template<typename T>
void Vector<T>::selectionSort()
{
	size_t min_index;
	for (size_t i = 0; i < size_ - 1; i++) {
		min_index = i;
		for (size_t j = i + 1; j < size_; j++) {
			if (array_[j] < array_[min_index])
				min_index = j;
		}
		if (min_index != i)
			std::swap(array_[i], array_[min_index]);
	}
}

template<typename T>
T& Vector<T>::operator[] (size_t index)
{
	if (index < 0 || index >= size_)
		throw std::invalid_argument("Индекс вне пределов вектора!");
	return array_[index];
}

template<typename T>
T& Vector<T>::operator[] (size_t index) const
{
	if (index < 0 || index >= size_)
		throw std::invalid_argument("Индекс вне пределов вектора!");
	return array_[index];
}

template<typename T>
std::ostream& operator<< (std::ostream& output, const Vector<T>& vector)
{
	for (size_t i = 0; i < vector.size_; i++)
		output << vector.array_[i] << '\n';
	return output;
}

template<typename T>
bool Vector<T>::operator== (const Vector<T>& other)
{
	if (size_ != other.size_)
		return false;
	bool isEqual = true;
	for (size_t i = 0; i < size_; i++) {
		isEqual = isEqual && (array_[i] == other.array_[i]);
		if (!isEqual)
			return false;
	}
	return true;
}

template<typename T>
bool Vector<T>::operator!= (const Vector<T>& other)
{
	if (size_ != other.size_)
		return true;
	bool isEqual = true;
	for (size_t i = 0; i < size_; i++) {
		isEqual = isEqual && (array_[i] == other.array_[i]);
		if (!isEqual)
			return true;
	}
	return false;
}

template<typename T>
bool Vector<T>::operator< (const Vector<T>& other)
{
	size_t minSize = std::min(size_, other.size_);
	for (size_t i = 0; i < minSize; i++) {
		if (array_[i] != other.array_[i])
			return array_[i] < other.array_[i];
	}
	return size_ < other.size_;
}

template<typename T>
bool Vector<T>::operator> (const Vector<T>& other)
{
	size_t minSize = std::min(size_, other.size_);
	for (size_t i = 0; i < minSize; i++) {
		if (array_[i] != other.array_[i])
			return array_[i] > other.array_[i];
	}
	return size_ > other.size_;
}

template<typename T>
bool Vector<T>::operator<= (const Vector<T>& other)
{
	size_t minSize = std::min(size_, other.size_);
	for (size_t i = 0; i < minSize; i++) {
		if (array_[i] != other.array_[i])
			return array_[i] < other.array_[i];
	}
	return size_ == other.size_;
}

template<typename T>
bool Vector<T>::operator>= (const Vector<T>& other)
{
	size_t minSize = std::min(size_, other.size_);
	for (size_t i = 0; i < minSize; i++) {
		if (array_[i] != other.array_[i])
			return array_[i] > other.array_[i];
	}
	return size_ == other.size_;
}

#endif // DATA_VECTOR_H
