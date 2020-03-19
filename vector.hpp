#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include<iostream>
#include<string>

class vector{
private:	
	int * m_data;
	size_t m_capacity;
	size_t m_size;
public:
	vector():
		m_capacity(1),
		m_size(0)
	{
		m_data = new int[m_capacity];
		for(size_t i = 0; i < m_size; ++i){
			m_data[i] = 0.0;	
		}
	}
	vector(const vector & obj)
	{
		m_data = new int[obj.m_size];
		m_capacity = obj.m_capacity;
		m_size = obj.m_size;	
		for (size_t i = 0; i< m_size; ++i){
			this->m_data[i] = obj.m_data[i];
		}
	}
	~vector()
	{
		delete[] m_data;		
	}

	/*! capacity */
	size_t size()
	{
		return m_size;
	}
	
	size_t capacity()
	{
		m_capacity = 2 * m_size;
		return m_capacity;
	}

	/*! modifiers */
	void insert(size_t index, int value)
	{
		if (index == m_capacity){
			push_back(value);	
		} else {
			 m_data[index] = value;
			 m_size++;
			}
		//		m_data[index] = value;
	}
	void resize()
	{
		//under construction
	}

	void erase(size_t index)
	{
		if (index == m_size){
			pop();
		} else {
			std::cout << "under construction" << std::endl;
			}
	}

	void push_back(int value )
	{
		if (m_size == m_capacity){
			int * temp = new int[2 * m_capacity ];
			
			for (int i = 0; i < m_size; ++i){
				temp[i] = m_data[i];
			}	
			delete [] m_data;
			m_capacity = m_size * 2;
			m_data = temp;
		}	
		m_data[m_size] = value;
		m_size++;
	}

	void pop()
	{
		if (m_size > 0) {
		  m_size--;
		} else {
			std::cout << "vector is empty" << std::endl;
			}		
	}
	
	int operator[](size_t & index)
	{
		return m_data[index];
	}

	int operator[](const size_t & index) const
	{
		return m_data[index];
	}

	int at(size_t index)
	{
		return m_data[index];
	}	
	/*! iterators */
	int * begin()
	{
		return m_data;	
	}
	
	int * end()
	{
		return (m_data + m_size);
	}
	
};

#endif //VECTOR_HPP_
