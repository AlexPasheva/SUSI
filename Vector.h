#pragma once
#ifndef DEFINE_VECTOR
#define DEFINE_VECTOR

#include <cstring>

constexpr int DEFAULT_CAPACITY = 32;

template <typename T>
class Vector
{
private:
	int capacity;
	int CurrentSize;
	T* storage;

	void Erase();
	void Resize();
	void CopyFrom(const Vector<T>& other);

public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();

	T& At(int index);
	const T& At(int index) const;
	int Find(const T& element) const;
	int Size() const;
	int GetCapacity() const;
	void PushBack(const T& el);
	bool Empty() const;
	void RemoveElement(const T& element);
	const T& operator[](int index) const;
	T& operator[](int index);
};
template <typename T>
void Vector<T>::Erase()
{
	delete[] this->storage;
}
template <typename T>
void Vector<T>::Resize()
{
	this->capacity *= 2;
	T* new_storage = new T[this->capacity];
	for (int i = 0; i < this->CurrentSize; i++)
	{
		new_storage[i] = this->storage[i];
	}
	delete[] this->storage;
	this->storage = new_storage;
}
template <typename T>
void Vector<T>::CopyFrom(const Vector<T>& other)
{
	this->capacity = other.capacity;
	this->CurrentSize = other.CurrentSize;
	this->storage = new T[this->capacity];
	for (int i = 0; i < other.CurrentSize; i++)
	{
		this->storage[i] = other.storage[i];
	}
}

template <typename T>
Vector<T>::Vector()
{
	this->capacity = DEFAULT_CAPACITY;
	this->CurrentSize = 0;
	this->storage = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	CopyFrom(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		Erase();
		CopyFrom(other);
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector() {
	Erase();
}

template <typename T>
T& Vector<T>::At(int index)
{
	return this->storage[index];
}
template <typename T>
const T& Vector<T>::At(int index) const
{
	return this->storage[index];
}
template <typename T>
int Vector<T>::Find(const T& element) const
{
	int index = -1;
	for (int i = 0; i < this->CurrentSize && index == -1; ++i)
	{
		if (this->storage[i] == element)
		{
			index = i;
		}
	}
	return index;
}
template <typename T>
int Vector<T>::Size() const
{
	return this->CurrentSize;
}
template <typename T>
int Vector<T>::GetCapacity() const
{
	return this->capacity;
}
template <typename T>
void Vector<T>::PushBack(const T& el)
{
	if (this->capacity == this->CurrentSize) {
		Resize();
	}

	this->storage[CurrentSize] = el;
	CurrentSize++;
}
template <typename T>
bool Vector<T>::Empty() const
{
	return this->CurrentSize == 0;
}
template <typename T>
void Vector<T>::RemoveElement(const T& element)
{
	int index;
	while ((index = this->Find(element)) >= 0)
	{
		for (int i = index; i < this->CurrentSize - 1; ++i)
		{
			this->storage[i + 1] = this->storage[i];
		}
		this->CurrentSize--;
	}
}
template <typename T>
const T& Vector<T>::operator[](int index) const
{
	return this->At(index);
}
template <typename T>
T& Vector<T>::operator[](int index)
{
	return this->At(index);
}
#endif
