#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include"vector.hpp"
#include<stdlib.h>
#include<cassert>
#include<iomanip>

#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RED "\033[01;031m"
#define RESET "\033[01;0m"


struct matrix{
protected:
	size_t row;
	size_t column;
	vector data;
	
static	void draw_matrix_value(const int & value)  //used without object
	{
		if (value >= 0){
			std::cout << "+";
			}
		std::cout<<std::right << std::setfill('0')  
			<<  std::setw(4) << std::right
			<<  value<< "  " ; 
	 }

static void draw_matrix_horiz_board(const int & col)
	{	
		std::cout << GREEN;
		std::cout << std::setw(4)<< " ";
		for (int i = 0; i < col; ++i){
			std::cout << " ";
			std::cout<<std::setfill(' ') 
		         <<  std::setw(4) << i << "  " ;
		}
		std::cout << std::endl;
		std::cout << RESET;
	}

static void draw_matrix_vert_board(const int & row)
	{
			std::cout << GREEN;
			std::cout<<std::setfill(' ') 
		         <<  std::setw(2) << row * 10 << "  " ;
			std::cout << RESET ;
	}


public:
	matrix() 
		: row(10),
		column(10)
	{
		assert(row == column && "You need quadratic matrix ... friend");
		for(size_t i = 0; i < column; ++i){
			for(size_t j = 0; j < row; ++j ){
					size_t l = i* column + j;
				data.insert(l, 0.0);
			}
		}
		//std::cout << "constructor" << std::endl;
	}

	matrix(const matrix & obj)
	{
		std::cout << "copy constuctor" << std::endl;
		this->row = obj.row;
		this->column = obj.column;
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < column; ++j){
				size_t index = i * column + j;
				double value  = obj.data[index];
				this->data.insert(index, value);	
			}
		}
	}
                    	
	double  operator()(const size_t & r, const size_t & c)  
	{
		size_t index = r* column + c;
		return data[index];
	}

	void operator()(size_t r, size_t c, double value)
	{
	
		size_t  index = r*column + c;	
		data.insert( index, value ); 
	}

	matrix  operator+(const matrix & obj)
	{
		matrix temp;
		std::cout << "operatror+ overload" << std::endl;
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < column; ++j){
				size_t	index = i * column + j;
				double value = this->data[index] + obj.data[index];
				temp(i, j , value);
			}
		}
			return temp;
	}

	matrix operator*(const matrix & obj)
	{
		std::cout << "operator* overload" << std::endl; 
		matrix temp;
	
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < column; ++j){
				double sum = 0;
				for (size_t k = 0; k < column; ++k){
				size_t index1 = row * i + k;
				size_t index2 = column* j + k;
				double value = this->data[index1] * obj.data[index2];
				sum += value; 
				temp(i, j , sum);
				}
			}
		}
		return temp;
	 }
	
	matrix & operator=(const matrix & obj)
	{
		std::cout << "operator= overload " << std::endl;
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < column; ++j){
				size_t index = i * column +j;
				double value = obj.data[index];
				this->data.insert(index, value);
			}
		}		
			return * this;
	}
	friend void operator<<(std::ostream & os, matrix & mat)
	{
	//	os << "operator<< overload"<< std::endl;
		size_t row = mat.row;
		size_t col = mat.column;
		draw_matrix_horiz_board(col);	
		for (size_t i = 0; i < row; ++i ){
			if ( (0 == i) ||  (0 !=  (i % 10)) ) { draw_matrix_vert_board(i);} 
				for (size_t j = 0; j < col; ++j){
					int value = mat(i,j);	
					draw_matrix_value(value);
				}
			std::cout << std::endl;
		}
	}
};

#endif //MATRIX_HPP_
