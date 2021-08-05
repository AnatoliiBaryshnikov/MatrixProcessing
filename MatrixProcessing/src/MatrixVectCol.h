/*

This class is a specialization of one-column Matrix

*/

#pragma once

#include "Matrix.h"

template <typename T, size_t R>
class MatrixVectCol : public Matrix <T, R, 1>
  {
  public:

  MatrixVectCol() : Matrix <T, R, 1>() {}
  MatrixVectCol(const std::vector<T>& vec) : Matrix <T, R, 1>(vec) {}
  MatrixVectCol(std::vector<T>&& vec) : Matrix <T, R, 1>(vec) {}
  MatrixVectCol(std::initializer_list<T>&& init_list) : Matrix <T, R, 1>(init_list) {}

  MatrixVectCol(const MatrixVectCol<T, R>&) = default;
  MatrixVectCol(MatrixVectCol<T, R>&&) = default;

  MatrixVectCol& operator=(const MatrixVectCol<T, R>&) = default;
  MatrixVectCol& operator=(MatrixVectCol<T, R>&&) = default;

  virtual ~MatrixVectCol() = default;

  const T& at(size_t row) const;
  T& at(size_t row);

  template <typename U, size_t V>
  friend std::ostream& operator<< (std::ostream& o, const MatrixVectCol<U, V>& vec_col);

  };


template<typename T, size_t R>
const T& MatrixVectCol<T, R>::at(size_t row) const
  {
  return this->m_data.at(row-1); // index of vector in math begins with 1 
  }


template<typename T, size_t R>
T& MatrixVectCol<T, R>::at(size_t row)
  {
  return this->m_data.at(row-1); // index of vector in math begins with 1 
  }


template <typename U, size_t V>
std::ostream& operator<< (std::ostream& o, const MatrixVectCol<U, V>& vec_col)
  {
  
  for (const U& elem : vec_col.m_data)
    {
    std::cout << "| ";
    std::cout << elem;
    std::cout << " |\n";
    }

  return o;
  }
