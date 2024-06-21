#pragma once
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(size_t capacity);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;

	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;

	~Vector();

	void push_back(const T& element);
	void push_back(T&& element);
	void pop_back();

	void insert(int index, const T& element); //insert element on index
	void insert(int index, T&& element);
	void erase(int index); //erase elemet at index

	void clear(); //clear data from array
	const T& operator[](unsigned index) const;
	T& operator[](unsigned index);

	bool empty() const;
	size_t getSize() const;

private:

	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other);
	void free();
	void resize(size_t newCap);

	T* vector = nullptr;
	size_t size = 0;
	size_t capacity = 0;
};

static size_t closestPowerOfAwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
};

template <typename T>
Vector<T>::Vector() :Vector(8) {}
template <typename T>
Vector<T>::Vector(size_t capacity) : size(0)
{
	this->capacity = closestPowerOfAwo(capacity);
	vector = new T[this->capacity];
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
template <typename T>
Vector<T>::~Vector()
{
	free();
}

template <typename T>
void Vector<T>::push_back(const T& element)
{
	if (size + 1 == capacity)
		resize(capacity * 2);

	vector[size++] = element;
}
template <typename T>
void Vector<T>::push_back(T&& element)
{
	if (size + 1 == capacity)
		resize(capacity * 2);

	vector[size++] = std::move(element);
}

template <typename T>
void Vector<T>::pop_back()
{
	erase(size - 1);
}

template <typename T>
void Vector<T>::insert(int index, const T& element)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (size + 1 == capacity)
		resize(capacity * 2);

	for (int i = size;i > index;i--)
	{
		vector[i] = vector[i - 1];
	}

	vector[index] = element;
	size++;
}
template <typename T>
void Vector<T>::insert(int index, T&& element)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (size + 1 == capacity)
		resize(capacity * 2);

	for (int i = size;i > index;i--)
	{
		vector[i] = vector[i - 1];
	}

	vector[index] = std::move(element);
	size++;
}

template <typename T>
void Vector<T>::erase(int index)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (!size)
		throw "Vector is already empty!";

	for (int i = index;i < size;i++)
		vector[i] = vector[i + 1];

	size--;
}

template <typename T>
void Vector<T>::clear()
{
	delete[] vector;
	size = 0;
	vector = new T[capacity];
}

template <typename T>
const T& Vector<T>::operator[](unsigned index) const
{
	if (index<0 || index>size)
		throw "Invalid index";

	return vector[index];
}
template <typename T>
T& Vector<T>:: operator[](unsigned index)
{
	if (index<0 || index>size)
		throw "Invalid index";

	return vector[index];
}

template <typename T>
bool Vector<T>::empty() const
{
	return size;
}
template <typename T>
size_t Vector<T>::getSize() const
{
	return size;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	vector = new T[other.capacity];

	for (size_t i = 0; i < other.size; i++)
		vector[i] = other.vector[i];

	size = other.size;
	capacity = other.capacity;
}
template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	vector = other.vector;
	size = other.size;
	capacity = other.capacity;

	other.vector = nullptr;
	other.size = other.capacity = 0;
}
template <typename T>
void Vector<T>::free()
{
	delete[] vector;
	size = capacity = 0;
}

template <typename T>
void Vector<T>::resize(size_t newCap)
{
	T* newData = new T[newCap];

	for (int i = 0;i < size;i++)
		newData[i] = vector[i];

	delete[] vector;

	vector = newData;
	capacity = newCap;
}
