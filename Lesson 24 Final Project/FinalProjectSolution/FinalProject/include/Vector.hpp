#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <exception>

template <typename T>
class FinalVector
{
private:
	T* m_arrayData;
	size_t m_currentSize;
	size_t m_capacity;
	void grow();
public:
	FinalVector();
	FinalVector(const FinalVector<T>& other);
	FinalVector<T>& operator=(const FinalVector<T>& other);
	~FinalVector();
	size_t size() const;
	T& operator[](size_t index);
	void push_back(const T& value);
	void pop_back();
	void erase(size_t index);
	void clear();
	friend std::ostream& operator<<(std::ostream& os, const FinalVector<T>& v)
	{
		for (size_t i = 0; i < v.m_currentSize; i++)
		{
			os << v.m_arrayData[i];
			if (i + 1 < v.m_currentSize)
			{
				os << " ";
			}
		}
		return os;
	}
};

template <typename T>
void FinalVector<T>::grow()
{
	size_t newCapacity;
	if (m_capacity == 0)
	{
		newCapacity = 1;
	}
	else
	{
		newCapacity = m_capacity * 2;
	}
	T* newData = new T[newCapacity];
	for (size_t i = 0; i < m_currentSize; i++)
	{
		newData[i] = m_arrayData[i];
	}
	delete[] m_arrayData;
	m_arrayData = newData;
	m_capacity = newCapacity;
}

template <typename T>
FinalVector<T>::FinalVector()
{
	m_arrayData = nullptr;
	m_currentSize = 0;
	m_capacity = 0;
}

template <typename T>
FinalVector<T>::FinalVector(const FinalVector<T>& other)
{
	m_currentSize = other.m_currentSize;
	m_capacity = other.m_capacity;
	m_arrayData = new T[m_capacity];
	for (size_t i = 0; i < m_currentSize; i++)
	{
		m_arrayData[i] = other.m_arrayData[i];
	}
}

template <typename T>
FinalVector<T>& FinalVector<T>::operator=(const FinalVector<T>& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] m_arrayData;
	m_currentSize = other.m_currentSize;
	m_capacity = other.m_capacity;
	m_arrayData = new T[m_capacity];
	for (size_t i = 0; i < m_currentSize; i++)
	{
		m_arrayData[i] = other.m_arrayData[i];
	}
	return *this;
}

template <typename T>
FinalVector<T>::~FinalVector()
{
	delete[] m_arrayData;
}

template <typename T>
size_t FinalVector<T>::size() const
{
	return m_currentSize;
}

template <typename T>
T& FinalVector<T>::operator[](size_t index)
{
	if (index >= m_currentSize)
	{
		throw std::exception();
	}
	return m_arrayData[index];
}

template <typename T>
void FinalVector<T>::push_back(const T& value)
{
	if (m_currentSize == m_capacity)
	{
		grow();
	}
	m_arrayData[m_currentSize] = value;
	m_currentSize++;
}

template <typename T>
void FinalVector<T>::pop_back()
{
	if (m_currentSize == 0)
	{
		throw std::exception();
	}
	m_currentSize--;
}

template <typename T>
void FinalVector<T>::erase(size_t index)
{
	if (index >= m_currentSize)
	{
		throw std::exception();
	}
	for (size_t i = index; i < m_currentSize - 1; i++)
	{
		m_arrayData[i] = m_arrayData[i + 1];
	}
	m_currentSize--;
}

template <typename T>
void FinalVector<T>::clear()
{
	m_currentSize = 0;
}

#endif