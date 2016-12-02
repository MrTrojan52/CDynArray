#pragma once
#include <stdio.h>
#include <iostream>

template <class T>
class CDArray
{
public:
	CDArray();
	CDArray(int size, T * a);
	CDArray(int size);
	CDArray(CDArray<T>& b);
	T getElement(int index);
	void setElement(int index, T val);
	T operator[](int index);
	void fillArrayFK();
	int getSize();
	~CDArray();

private:
	int _size;
	T * _arr;
};

template <class T>
T CDArray<T>::getElement(int index)
{
	if (index >= 0 && index <= _size - 1)
		return _arr[index];
	else
		return NULL;
}

template <class T>
void CDArray<T>::setElement(int index, T val)
{
	if (index >= 0 && index <= _size - 1)
		_arr[index] = val;
}

template <class T>
T CDArray<T>::operator[](int index)
{
	if (index >= 0 && index <= _size - 1)
		return _arr[index];
	else
		return NULL;
}

template <class T>
void CDArray<T>::fillArrayFK()
{
	std::cout << std::endl << "Array of " << typeid(T).name() << ". Size = " << _size << std::endl;
	std::cout << "Enter " << _size << " values" << std::endl;

	for (int  i = 0; i < _size; i++)
	{
		
		std::cin >> _arr[i];

	}
	fflush(stdin);
}


template <class T>
int CDArray<T>::getSize()
{
	return _size;
}

template <class T>
CDArray<T>::CDArray( CDArray<T>& b)
{
	_size = b._size;
	delete[] _arr;
	_arr = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = b.getElement(i);
	}
}

template <class T>
CDArray<T>::CDArray(int size,T * a )
{
	if (size <= 0)
		size = 1;
	_size = size;
	if (_arr)
		delete[] _arr;
	_arr = new T[_size];
	if (a == NULL)
	{
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = NULL;
		}
	}
	else
	{
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = a[i];
		}
	}
}

template <class T>
CDArray<T>::CDArray(int size)
{
	if (size <= 0)
		size = 1;
	if (_arr)
		delete[] _arr;
	_size = size;
	_arr = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = NULL;
	}
}

template <class T>
CDArray<T>::CDArray()
{
	_size = 1;
	_arr = new T[_size];
	_arr[0] = NULL;
}
template <class T>
CDArray<T>::~CDArray()
{
	delete[] _arr;
}