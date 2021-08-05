/*

This class is a specialization of one-row Matrix

*/

#pragma once

#include "Matrix.h"

template <typename T, size_t C>
class MatrixVectRow : public Matrix <T, 1, C>
  {
  public:

  MatrixVectRow() : Matrix <T, 1, C>() {}
  MatrixVectRow(const std::vector<T>& vec) : Matrix <T, 1, C>(vec) {}
  MatrixVectRow(std::vector<T>&& vec) : Matrix <T, 1, C>(vec) {}
  MatrixVectRow(std::initializer_list<T>&& init_list) : Matrix <T, 1, C>(init_list) {}

  MatrixVectRow(const MatrixVectRow<T, C>&) = default;
  MatrixVectRow(MatrixVectRow<T, C>&&) = default;
   
  MatrixVectRow& operator=(const MatrixVectRow<T, C>&) = default;
  MatrixVectRow& operator=(MatrixVectRow<T, C>&&) = default;

  virtual ~MatrixVectRow() = default;

  const T& at(size_t col) const;
  T& at(size_t col);

  template <typename U, size_t V>
  friend std::ostream& operator<< (std::ostream& o, const MatrixVectRow<U, V>& vec_row);
  };


template<typename T, size_t C>
const T& MatrixVectRow<T, C>::at(size_t col) const
  {
  return this->m_data.at(col-1); // indexing of vector in math begins with 1 
  }


template<typename T, size_t C>
T& MatrixVectRow<T, C>::at(size_t col)
  {
  return this->m_data.at(col-1); // indexing of vector in math begins with 1 
  }


template <typename U, size_t V>
std::ostream& operator<< (std::ostream& o, const MatrixVectRow<U, V>& vec_row)
  {
  std::cout << "| ";
  for (const U& elem : vec_row.m_data)
    {
    std::cout << elem;
    if (&elem != &vec_row.m_data.back())
      {
      std::cout << "\t";
      }
    }
  std::cout << " |\n";

  return o;
  }
