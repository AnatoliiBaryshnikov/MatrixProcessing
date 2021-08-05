/*

This class represents general interface of Matrix Processors

*/

#pragma once

#include <vector>
#include "Matrix.h"

template <typename Implementation>
class IMatrixProcessor 
  {
  public:

  IMatrixProcessor() = default;
  ~IMatrixProcessor() = default;

  template <typename T, typename U>
  decltype(auto) perform_operation(const T& lhs, const U& rhs) const
    {
    return (static_cast<const Implementation*>(this))->perform_operation(lhs, rhs);
    }

  };
 