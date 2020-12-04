#pragma once
#include <iostream>
#include <cassert>
template <typename T>
class Vector
{
	T* arr;
	int size;
	int capacity;
public:
	Vector();
	Vector(const int size);
	Vector(int size, const T& value);
	int get_size() const;
	int get_capacity() const;
	bool empty() const;
	void reserve(const int n);
	void resize(const int n);
	void resize(const int n, const T& value);
	void push_back(const T& value);
	void pop_back();
	void clear();
	void shrink_to_fit();
	T& operator[](const int index);
	T operator[](const int index) const;
	T& at(const int index);
	T at(const int index) const;
	~Vector();
};

template<typename T>
inline Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 1;
	this->arr = new T[1];
}

template<typename T>
inline Vector<T>::Vector(const int size)
{
	this->size = size;
	this->capacity = size * 2;
	this->arr = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(int size, const T& value)
{
	this->size = size;
	if (size == 0)
	{
		this->capacity = 1;
	}
	else
	{
		this->capacity = 2 * size;
	}
	arr = new T[capacity];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

template<typename T>
inline int Vector<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline int Vector<T>::get_capacity() const
{
	return this->capacity;
}

template<typename T>
inline bool Vector<T>::empty() const
{
	if (this->size == 0)
	{
		return true;
	}
}

template<typename T>
inline void Vector<T>::reserve(const int n)
{
	T* tmp = new T[n];
	for (int i = 0; i < min(this->size, n); i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size = min(this->size, n);
	this->capacity = n;
}

template<typename T>
inline void Vector<T>::resize(const int n)
{
	if (this->capacity < n)
	{
		T* tmp = new T[n];
		int i = 0;
		for (; i < size; i++)
		{
			tmp[i] = this->arr[i];
		}
		for (; i < n; i++)
		{
			tmp[i] = T();
		}
		this->size = n;
		this->capacity = n;
		delete[]this->arr;
		this->arr = tmp;
	}
	else
	{
		this->size = n;
	}
}

template<typename T>
inline void Vector<T>::resize(const int n, const T& value)
{

	if (this->capacity < n)
	{
		T* tmp = new T[n];
		int i = 0;
		for (; i < size; i++)
		{
			tmp[i] = this->arr[i];
		}
		for (; i < n; i++)
		{
			tmp[i] = value;
		}
		this->size = n;
		this->capacity = n;
		delete[]this->arr;
		this->arr = tmp;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = value;
		}
		this->size = n;
	}

}

template<typename T>
inline void Vector<T>::push_back(const T& value)
{
	if (this->size < this->capacity)
	{
		this->arr[size] = value;
		this->size++;
		return;
	}
	else
	{
		this->capacity *= 2;
		T* tmp = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->arr[i];
		}
		tmp[this->size] = value;
		delete[]this->arr;
		this->arr = tmp;
		this->size++;
	}
}

template<typename T>
inline void Vector<T>::pop_back()
{
	this->size--;
}

template<typename T>
inline void Vector<T>::clear()
{
	T* tmp = new T[this->capacity];
	delete[]this->arr;
	this->arr = tmp;
	this->size = 0;
}

template<typename T>
inline void Vector<T>::shrink_to_fit()
{
	if (this->size == this->capacity)
	{
		return;
	}
	T* tmp = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->capacity = this->size;
}

template<typename T>
inline T& Vector<T>::operator[](const int index)
{
	return this->arr[index];
}

template<typename T>
inline T Vector<T>::operator[](const int index) const
{
	return this->arr[index];
}

template<typename T>
inline T& Vector<T>::at(const int index)
{
	assert((index >= this->size || index < 0) && "Index out of range");
	return this->arr[index];
}

template<typename T>
inline T Vector<T>::at(const int index) const
{
	assert((index >= this->size || index < 0) && "Index out of range");
	return this->arr[index];
}

template<typename T>
inline Vector<T>::~Vector()
{
	if (capacity != 0)
	{
		delete[]arr;
	}

}