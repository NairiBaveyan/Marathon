#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    ~Vector();

public:
    void erase(size_t);
    void clear();
    void insert(size_t pos,T val);
    bool is_empty();
    size_t capacity();
    void push_Back(const T&);
    size_t Size() const;
    T& operator[](size_t index);
    const T& operator[](size_t index)const;
    void pop_back();

private:
    void ReAlloc(size_t newCapacity);

private:
    T *m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};


template <typename T>
void Vector<T>::insert(size_t pos, T val)
{
	if(pos > m_Size) return;
	m_Data[pos - 1] = val;
}

template <typename T>
void Vector<T>::clear()
{
	m_Size = 0;
}

template <typename T>
void Vector<T>::erase(size_t pos)
{
	if(pos > m_Size - 1) return;
	for(int i = pos - 1; i < m_Size - 1; ++i)
	{
		m_Data[i] = m_Data[i + 1];
	}
	--m_Size;
}

template <typename T>
bool Vector<T>::is_empty()
{
	if(m_Size==0)
	{
		return true;
	}
	return false;
	

}


template <typename T>
void Vector<T>::pop_back()
{
	--m_Size;
}



template <typename T>
Vector<T>::Vector()
{
    //allocate 1 block of memorys
    ReAlloc(1);
}




template <typename T>
void Vector<T>::push_Back(const T &value)
{
    if (m_Size >= m_Capacity)
    {
        ReAlloc(m_Capacity*2);
    }
    m_Data[m_Size] = value;
    ++m_Size;
}




template <typename T>
void Vector<T>::ReAlloc(size_t newCapacity)
{
    //1 allocate a new block of memory
    //2 copy/move the old elements into new block
    //3 delete

    
    if(m_Capacity==0)
    {
	    m_Capacity = newCapacity;
	    m_Data = new T[m_Capacity];
    }else
    {
	m_Capacity = newCapacity;
        T* newBlock = new T[m_Capacity];
	for(size_t i{};i<m_Size;++i )
	{
		newBlock[i]=m_Data[i];
	}
    delete[] m_Data;
    m_Capacity += newCapacity;
    m_Data = newBlock;
    newBlock = nullptr;
    }  
}

template <typename T>
size_t Vector<T>::Size()const
{
    return m_Size;
}


template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return m_Data[index];
}


template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return m_Data[index];
}

template <typename T>
Vector<T>::~Vector()
{
        delete[] m_Data;   
}

#endif /*VECTOR_H_*/
