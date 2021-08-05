#pragma once

#include <vector>
#include <cassert>
#include "IMatrixProcessor.h"

/// <summary>
/// This namespace contains implementations of IMatrixProcessor
/// </summary>
namespace MatrixProcessors {

  /// <summary>
  /// Adds scalar to every element of the matrix.
  /// </summary>
  class AddScalar : public IMatrixProcessor<AddScalar>
    {
      public:

      AddScalar() = default;
      ~AddScalar() = default;

      template <typename U, typename V, size_t R, size_t C >
      auto perform_operation(const Matrix<U, R, C>& lhs, const V& rhs) const
        {

        const std::vector<U>& lhs_data = lhs.get_data();

        auto type_val = lhs_data[0] + rhs;

        std::vector<decltype(type_val)> result_data(R * C);
        for (size_t i = 0; i < result_data.size(); ++i)
          {
          result_data[i] = lhs_data[i] + rhs;
          }

        Matrix<decltype(type_val), R, C> result(std::move(result_data));

        return result;
        }
    };


  /// <summary>
  /// Subtracts scalar from every element of the matrix.
  /// </summary>
  class SubtractScalar : public IMatrixProcessor<SubtractScalar>
    {
      public:

      SubtractScalar() = default;
      ~SubtractScalar() = default;

      template <typename U, typename V, size_t R, size_t C >
      auto perform_operation(const Matrix<U, R, C>& lhs, const V& rhs)  const
        {

        const std::vector<U>& lhs_data = lhs.get_data();

        auto type_val = lhs_data[0] - rhs;

        std::vector<decltype(type_val)> result_data(R * C);
        for (size_t i = 0; i < result_data.size(); ++i)
          {
          result_data[i] = lhs_data[i] - rhs;
          }

        Matrix<decltype(type_val), R, C> result(std::move(result_data));

        return result;
        }
    };


  /// <summary>
  /// Multiply every element of the matrix on scalar.
  /// </summary>
  class MultiplyScalar : public IMatrixProcessor<MultiplyScalar>
    {
      public:

      MultiplyScalar() = default;
      ~MultiplyScalar() = default;

      template <typename U, typename V, size_t R, size_t C >
      auto perform_operation(const Matrix<U, R, C>& lhs, const V& rhs)  const
        {

        const std::vector<U>& lhs_data = lhs.get_data();

        auto type_val = lhs_data[0] * rhs;

        std::vector<decltype(type_val)> result_data(R * C);
        for (size_t i = 0; i < result_data.size(); ++i)
          {
          result_data[i] = lhs_data[i] * rhs;
          }

        Matrix<decltype(type_val), R, C> result(std::move(result_data));

        return result;
        }
    };


  /// <summary>
  /// Adds every element of the first matrix to every element of the second.
  /// </summary>
  class AddMatrix : public IMatrixProcessor<AddMatrix>
    {
      public:

      AddMatrix() = default;
      ~AddMatrix() = default;

      template <typename U, typename V, size_t R, size_t C >
      auto perform_operation(const Matrix<U, R, C>& lhs, const Matrix<V, R, C>& rhs)  const
        {

        const std::vector<U>& lhs_data = lhs.get_data();
        const std::vector<V>& rhs_data = rhs.get_data();

        assert (lhs_data.size() == rhs_data.size());

        auto type_val = lhs_data[0] + rhs_data[0];

        std::vector<decltype(type_val)> result_data(R * C);
        for (size_t i = 0; i < result_data.size(); ++i)
          {
          result_data[i] = lhs_data[i] + rhs_data[i];
          }

        Matrix<decltype(type_val), R, C> result(std::move(result_data));

        return result;
        }
    };


  /// <summary>
  /// Multiplies two matrices
  /// </summary>
  class MultiplyMatrix : public IMatrixProcessor<MultiplyMatrix>
    {
      public:

      MultiplyMatrix() = default;
      ~MultiplyMatrix() = default;
  
      // General realization
      template <typename T, typename U, size_t R1, size_t C1_R2, size_t C2>
      auto perform_operation(const Matrix<T, R1, C1_R2>& lhs, const Matrix<U, C1_R2, C2>& rhs)  const
        {
        const std::vector<T>& lhs_data = lhs.get_data();
        const std::vector<U>& rhs_data = rhs.get_data();
  
        auto type_val = lhs_data[0] + rhs_data[0];
  
        std::vector<decltype(type_val)> result_data(R1 * C2);

        size_t R1_counter = 0;
        size_t C2_counter = 0;
        for (size_t i = 0; i < result_data.size(); i++)
          {
          if (C2_counter >= C2) 
            { 
            C2_counter = 0;
            R1_counter += C1_R2;
            }

          for (size_t j = 0; j < C1_R2; j++)
            {
            result_data[i] += lhs_data[j + R1_counter] * rhs_data[j*C2 + C2_counter];
            }
          
          ++C2_counter;
          }

        Matrix<decltype(type_val), R1, C2> result(std::move(result_data));
  
        return result;
        }

     
      // Specialized realization for vector-row x vector-col case
      template <typename T, typename U, size_t C1_R2>
      auto perform_operation(const Matrix<T, 1, C1_R2>& lhs, const Matrix<U, C1_R2, 1>& rhs)  const
        {
        const std::vector<T>& lhs_data = lhs.get_data();
        const std::vector<U>& rhs_data = rhs.get_data();

        auto type_val = lhs_data[0] + rhs_data[0];

        decltype(type_val) inner_product = 0;

        for (size_t i = 0; i < lhs_data.size(); ++i)
          {
          inner_product += lhs_data[i] * rhs_data[i];
          }

        Matrix<decltype(type_val), 1, 1> result({ inner_product });

        return result;
        }

    };


  }
