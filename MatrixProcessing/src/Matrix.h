/*

This class represents array-based Matrix

*/ 

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <type_traits>
#include "IMatrixProcessor.h"


template <typename T, size_t R, size_t C>
class Matrix
  {
  protected:

  std::vector<T> m_data;
  size_t m_rows = R;
  size_t m_cols = C;


  public:

  Matrix();
  Matrix(const std::vector<T>& vec);
  Matrix(std::vector<T>&& vec);
  Matrix(std::initializer_list<T>&& init_list);

  Matrix(const Matrix<T,R,C>&) = default;
  Matrix(Matrix<T, R, C>&&) = default;
  virtual ~Matrix() = default;

  Matrix& operator=(const Matrix&) = default;
  Matrix& operator=(Matrix&&) = default;

  const std::vector<T>& get_data() const;
  const size_t get_n_rows() const;
  const size_t get_n_cols() const;

  const T& at(size_t row, size_t col) const;
  T& at(size_t row, size_t col);

  template <typename U, size_t V, size_t X>
  friend std::ostream& operator<< (std::ostream& o, const Matrix<U, V, X>& mat);

  template <typename U, size_t V, size_t X>
  friend bool operator== (const Matrix<U, V, X>& mat1, const Matrix<U, V, X>& mat2);

  template <typename U, size_t V, size_t X>
  friend bool operator!= (const Matrix<U, V, X>& mat1, const Matrix<U, V, X>& mat2);

  template <typename P, typename U, std::enable_if_t<std::is_arithmetic_v<U>>* = nullptr>
  auto UnaryOperation(const IMatrixProcessor<P>& imp, const U& scal) const; 

  template <typename P, typename U, size_t V, size_t X>
  auto BinaryOperation(const IMatrixProcessor<P>& imp, const Matrix<U, V, X>& mat) const;

  };


template <typename T, size_t R, size_t C>
Matrix<T, R, C>::Matrix()
  : m_data(R*C, 0)
  {
  static_assert(R*C > 0);
  }


template <typename T, size_t R, size_t C>
Matrix<T, R, C>::Matrix(const std::vector<T>& vec)
  {
  static_assert(R * C > 0);
  if (vec.size() != R * C)
    {
    throw std::length_error("Length of the provided vector doesn`t match matrix size");
    }
  m_data = vec;
  }


template <typename T, size_t R, size_t C>
Matrix<T, R, C>::Matrix(std::initializer_list<T>&& init_list)
  {
  static_assert(R * C > 0);
  if (init_list.size() != R * C)
    {
    throw std::length_error("Length of the provided initializer_list doesn`t match matrix size");
    }
  m_data = init_list;
  }


template <typename T, size_t R, size_t C>
Matrix<T, R, C>::Matrix(std::vector<T>&& vec)
  {
  static_assert(R * C > 0);
  if (vec.size() != R * C)
    {
    throw std::length_error("Length of vector doesn`t match matrix size");
    }
  m_data = std::move(vec);
  }


template <typename T, size_t R, size_t C>
const std::vector<T>& Matrix<T, R, C>::get_data() const
  {
  return m_data;
  }


template <typename T, size_t R, size_t C>
const size_t Matrix<T, R, C>::get_n_rows() const
  {
  return m_rows;
  }


template <typename T, size_t R, size_t C>
const size_t Matrix<T, R, C>::get_n_cols() const
  {
  return m_cols;
  }


template <typename T, size_t R, size_t C>
const T& Matrix<T, R, C>::at(size_t row, size_t col) const
  {
  return m_data.at(row*C+col-C-1);
  }


template <typename T, size_t R, size_t C>
T& Matrix<T, R, C>::at(size_t row, size_t col)
  {
  return m_data.at(row * C + col - C - 1);
  }


template <typename U, size_t V, size_t X>
std::ostream& operator<< (std::ostream& ostr, const Matrix<U, V, X>& mat)
  {
  size_t col_counter = 0;
  size_t row_counter = 0;

  std::cout << "| ";
  for (const U& elem : mat.m_data)
    {
    std::cout << elem;
    ++col_counter;
    if (col_counter == mat.m_cols)
      {
      std::cout << " |" << std::endl;
      col_counter = 0;
      ++row_counter;
      if (row_counter < mat.m_rows)
          {
          std::cout << "| ";
          }
      continue;
      }
    std::cout << "\t";
    }

  return ostr;
  }


template <typename U, size_t V, size_t X>
bool operator==(const Matrix<U, V, X>& mat1, const Matrix<U, V, X>& mat2)
  {
  return mat1.m_rows == mat2.m_rows && mat1.m_cols == mat2.m_cols && mat1.m_data == mat2.m_data;
  }


template <typename U, size_t V, size_t X>
bool operator!=(const Matrix<U, V, X>& mat1, const Matrix<U, V, X>& mat2)
  {
  return !(mat1 == mat2);
  }


template <typename T, size_t R, size_t C >
template <typename P, typename U, std::enable_if_t<std::is_arithmetic_v<U>>*>
auto Matrix<T, R, C>::UnaryOperation(const IMatrixProcessor<P>& imp, const U& scal) const
  {
  auto result = imp.perform_operation(*this, scal);
  return result;
  }


template <typename T, size_t R, size_t C >
template <typename P, typename U, size_t V, size_t X>
auto Matrix<T, R, C>::BinaryOperation(const IMatrixProcessor<P>& imp, const Matrix<U, V, X>& mat) const
  {
  auto result = imp.perform_operation(*this, mat);
  return result;
  }
