#pragma once

#include <cassert>
#include "Matrix.h"
#include "MatrixVectRow.h"
#include "MatrixVectCol.h"
#include "MatrixProcessors.h"

/// <summary>
/// Contains tests for Matrices and Matrix Processors
/// </summary>
namespace Tests {

  void create_empty_matrix();
  void test_nonconst_get_and_value_change();
  void test_const_get();
  void test_get_throws_exception_out_of_bound();
  void test_equality();
  void test_sum_mat_int_mat_double();
  void test_sum_mat_float_mat_double();
  void test_sum_mat_int_scalar_double();
  void test_subtract_mat_int_scalar_double();
  void test_multiply_mat_int_scalar_double();
  void test_multiply_mat_int_3_1_mat_int_1_3();
  void test_multiply_mat_int_1_3_mat_double_3_1();
  void test_multiply_vec_row_int_1_3_vec_col_double_3_1();
  void test_multiply_mat_int_1_3_mat_int_3_4();
  void test_multiply_mat_int_3_3_mat_int_3_2();
  void test_multiply_mat_int_3_4_mat_int_4_1();
  void test_multiply_mat_int_4_4_mat_float_4_4();

  void run_all_automatic_tests()
    {
    std::cout << "\n\n\t [ SIMPLE TESTING ]\n\n";
    create_empty_matrix();
    test_nonconst_get_and_value_change();
    test_const_get();
    test_get_throws_exception_out_of_bound();
    test_equality();
    test_sum_mat_int_mat_double();
    test_sum_mat_float_mat_double();
    test_sum_mat_int_scalar_double();
    test_subtract_mat_int_scalar_double();
    test_multiply_mat_int_scalar_double();
    test_multiply_mat_int_3_1_mat_int_1_3();
    test_multiply_mat_int_1_3_mat_double_3_1();
    test_multiply_vec_row_int_1_3_vec_col_double_3_1();
    test_multiply_mat_int_1_3_mat_int_3_4();
    test_multiply_mat_int_3_3_mat_int_3_2();
    test_multiply_mat_int_3_4_mat_int_4_1();
    test_multiply_mat_int_4_4_mat_float_4_4();
    }



  void test_console_output()
    {
    std::cout << "\n\n\t [ CONSOLE OUTPUT ]\n\n";
    std::cout << "\n >>> Matrix<int, 4, 4>\n";
    std::cout << Matrix<int, 4, 4> {} << std::endl;
    std::cout << "\n >>> MatrixVectRow<int, 4>\n";
    std::cout << MatrixVectRow<int, 4> {} << std::endl;
    std::cout << "\n >>> MatrixVectCol<int, 4>\n";
    std::cout << MatrixVectCol<int, 4> {} << std::endl;
    std::cout << "\n >>> Matrix<double, 4, 4> ... yeah, crap :)\n";
    std::cout << Matrix<double, 4, 4>  { 0.125, 0,                 0,   0,
                                         0,     0,                 0,   0.55555,
                                         0,     0.151515151511111, 0,   0,
                                         0,     0,                 0.2, 0 } << std::endl;

    }



  void create_empty_matrix()
    {
    std::cout << " >>> create_empty_matrix()\t\t\t\t";
    Matrix<int, 4, 4> mat;

    Matrix<int, 4, 4> expected_result = { 0, 0, 0, 0,
                                          0, 0, 0, 0,
                                          0, 0, 0, 0,
                                          0, 0, 0, 0 };

    expected_result != mat ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_nonconst_get_and_value_change()
    {
    std::cout << " >>> test_nonconst_get_and_value_change()\t\t";
    Matrix<int, 4, 4> mat({ 0,  1,  2,  3,
                            4,  5,  6,  7,
                            8,  9,  10, 11,
                            12, 13, 14, 15 });
    mat.at(1, 1) = 111;
    mat.at(1, 2) = 112;
    mat.at(3, 4) = 113;
    mat.at(4, 1) = 114;
    mat.at(4, 4) = 115;

    std::vector<int> expected_result = { 111, 112, 2,  3,
                                         4,   5,   6,  7,
                                         8,   9,   10, 113,
                                         114, 13,  14, 115 };

    expected_result != mat.get_data() ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_const_get()
    {
    std::cout << " >>> test_const_get()\t\t\t\t\t";
    const Matrix<int, 4, 4> mat({ 0,  1,  2,  3,
                                  4,  5,  6,  7,
                                  8,  9,  10, 11,
                                  12, 13, 14, 15 });

    0  != mat.at(1, 1) ? std::cout << "...#1 FAILED !!!" : std::cout << "...#1 PASSED";
    1  != mat.at(1, 2) ? std::cout << "...#2 FAILED !!!" : std::cout << "...#2 PASSED";
    11 != mat.at(3, 4) ? std::cout << "...#3 FAILED !!!" : std::cout << "...#3 PASSED";
    12 != mat.at(4, 1) ? std::cout << "...#4 FAILED !!!" : std::cout << "...#4 PASSED";
    15 != mat.at(4, 4) ? std::cout << "...#5 FAILED !!!" : std::cout << "...#5 PASSED";
    
    const MatrixVectCol<int, 4> vec_c({ 1,  
                                        2,  
                                        3,  
                                        4 });

    1 != vec_c.at(1) ? std::cout << "...#6 FAILED !!!" : std::cout << "...#6 PASSED";
    4 != vec_c.at(4) ? std::cout << "...#7 FAILED !!!" : std::cout << "...#7 PASSED";

    const MatrixVectRow<int, 4> vec_r({ 1, 2, 3, 4 });

    1 != vec_r.at(1) ? std::cout << "...#8 FAILED !!!" : std::cout << "...#8 PASSED";
    4 != vec_r.at(4) ? std::cout << "...#9 FAILED !!!" : std::cout << "...#9 PASSED";

    std::cout << "\n";
    }



  void test_get_throws_exception_out_of_bound()
    {
    std::cout << " >>> test_get_throws_exception_out_of_bound()\t\t";
    const Matrix<int, 4, 4> mat({ 0,  1,  2,  3,
                                  4,  5,  6,  7,
                                  8,  9,  10, 11,
                                  12, 13, 14, 15 });
    try
      {
      mat.at(4, 5);
      std::cout << "...#1 FAILED !!!";
      }
    catch (const std::exception& e)
      {
      std::cout << "...#1 PASSED";
      }
    
    try
      {
      mat.at(5, 4);
      std::cout << "...#2 FAILED !!!";
      }
    catch (const std::exception& e)
      {
      std::cout << "...#2 PASSED";
      }
    
    try
      {
      mat.at(5, 5);
      std::cout << "...#3 FAILED !!!";
      }
    catch (const std::exception& e)
      {
      std::cout << "...#3 PASSED";
      }

    try
      {
      mat.at(5, 5);
      std::cout << "...#4 FAILED !!!";
      }
    catch (const std::exception& e)
      {
      std::cout << "...#4 PASSED";
      }
    
    try
      {
      mat.at(0, 0);
      std::cout << "...#5 FAILED !!!";
      }
    catch (const std::exception& e)
      {
      std::cout << "...#5 PASSED";
      }
    
    std::cout << "\n";
    }

  void test_equality()
    {
    std::cout << " >>> test_equality()\t\t\t\t\t";
    Matrix<int, 4, 4> mat_int1({ -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10 });

    Matrix<int, 4, 4> mat_int2({ -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10 });

    mat_int1 != mat_int2 ? std::cout << "...#1 FAILED !!!" : std::cout << "...#1 PASSED";
    mat_int1 == mat_int2 ? std::cout << "...#2 PASSED" : std::cout << "...#2 FAILED !!!";

    Matrix<int, 4, 4> mat_int3({ -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10 });

    Matrix<int, 4, 4> mat_int4({ 0, 0, 0, 0,
                                 0, 0, 0, 0,
                                 0, 0, 0, 0,
                                 0, 0, 0, 0 });

    mat_int3 == mat_int4 ? std::cout << "...#3 FAILED !!!" : std::cout << "...#3 PASSED";
    mat_int3 != mat_int4 ? std::cout << "...#4 PASSED" : std::cout << "...#4 FAILED !!!";

    std::cout << "\n";
    }



  void test_sum_mat_int_mat_double()
    {
    std::cout << " >>> test_sum_mat_int_mat_double()\t\t\t";
    Matrix<int, 4, 4> mat_int ({ -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10,
                                 -10, -10, -10, -10 });

    Matrix<double, 4, 4> mat_double({ 10.5, 10.5, 10.5, 10.5,
                                     10.5, 10.5, 10.5, 10.5,
                                     10.5, 10.5, 10.5, 10.5,
                                     10.5, 10.5, 10.5, 10.5 });

    auto mat_result = mat_int.BinaryOperation(MatrixProcessors::AddMatrix{}, mat_double);

    Matrix<double, 4, 4> expected_result = { 0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_sum_mat_float_mat_double()
    {
    std::cout << " >>> test_sum_mat_float_mat_double()\t\t\t";
    const Matrix<float, 4, 4> mat_float({ -10.0, -10.0, -10.0, -10.0,
                                          -10.0, -10.0, -10.0, -10.0,
                                          -10.0, -10.0, -10.0, -10.0,
                                          -10.0, -10.0, -10.0, -10.0 });

    const Matrix<double, 4, 4> mat_double({ 10.5, 10.5, 10.5, 10.5,
                                            10.5, 10.5, 10.5, 10.5,
                                            10.5, 10.5, 10.5, 10.5,
                                            10.5, 10.5, 10.5, 10.5 });

    auto mat_result = mat_float.BinaryOperation(MatrixProcessors::AddMatrix{}, mat_double);

    Matrix<double, 4, 4> expected_result = { 0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_sum_mat_int_scalar_double()
    {
    std::cout << " >>> test_sum_mat_int_scalar_double()\t\t\t";
    Matrix<int, 4, 4> mat_int({ -10, -10, -10, -10,
                              -10, -10, -10, -10,
                              -10, -10, -10, -10,
                              -10, -10, -10, -10 });

    auto mat_result = mat_int.UnaryOperation(MatrixProcessors::AddScalar{}, 10.5);

    Matrix<double, 4, 4> expected_result = { 0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_subtract_mat_int_scalar_double()
    {
    std::cout << " >>> test_subtract_mat_int_scalar_double()\t\t";
    Matrix<int, 4, 4> mat_int({ -10, -10, -10, -10,
                                -10, -10, -10, -10,
                                -10, -10, -10, -10,
                                -10, -10, -10, -10 });

    auto mat_result = mat_int.UnaryOperation(MatrixProcessors::SubtractScalar{}, -10.5);

    Matrix<double, 4, 4> expected_result = { 0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5,
                                             0.5, 0.5, 0.5, 0.5 };
     
    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }


  void test_multiply_mat_int_scalar_double()
    {
    std::cout << " >>> test_multiply_mat_int_scalar_double()\t\t";
    const Matrix<int, 4, 4> mat_int({ -10, -10, -10, -10,
                                    -10, -10, -10, -10,
                                    -10, -10, -10, -10,
                                    -10, -10, -10, -10 });

    auto mat_result = mat_int.UnaryOperation(MatrixProcessors::MultiplyScalar{}, -2.0);

    Matrix<double, 4, 4> expected_result = { 20.0, 20, 20, 20,
                                             20,   20, 20, 20,
                                             20,   20, 20, 20,
                                             20,   20, 20, 20 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_multiply_mat_int_3_1_mat_int_1_3()
    {
    std::cout << " >>> test_multiply_mat_int_3_1_mat_int_1_3()\t\t";
    const Matrix<int, 3, 1> mat_int1({ 1, 
                                       2, 
                                       3 });

    const Matrix<int, 1, 3> mat_int2({ 1, 2, 3 });

    auto mat_result = mat_int1.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, mat_int2);

    Matrix<int, 3, 3> expected_result = { 1, 2, 3,
                                          2, 4, 6,
                                          3, 6, 9 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_multiply_mat_int_1_3_mat_double_3_1()
    {
    std::cout << " >>> test_multiply_mat_int_1_3_mat_int_3_1()\t\t";

    const Matrix<int, 1, 3> mat_int1({ 1, 2, 3 });

    const Matrix<double, 3, 1> mat_int2({ 1,
                                          2,
                                          3 });

    auto mat_result = mat_int1.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, mat_int2);

    Matrix<double, 1, 1> expected_result = { 14 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";

    }



  void test_multiply_vec_row_int_1_3_vec_col_double_3_1()
    {
    std::cout << " >>> test_multiply_vec_row_int_1_3_vec_col_double_3_1()\t";

    const MatrixVectRow<int, 3> vec_r({ 1, 2, 3 });

    const MatrixVectCol<double, 3> vec_c({ 1.5,
                                           2,
                                           3 });

    auto mat_result = vec_r.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, vec_c);

    Matrix<double, 1, 1> expected_result { 14.5 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";

    }



  void test_multiply_mat_int_1_3_mat_int_3_4()
    {
    std::cout << " >>> test_multiply_mat_int_1_3_mat_int_3_4()\t\t";

    Matrix<int, 1, 3> mat_int1({ 1, 2, 3 });

    Matrix<int, 3, 4> mat_int2({ 1, 2,  3,  4,
                                 5, 6,  7,  8,
                                 9, 10, 11, 12 });

    auto mat_result = mat_int1.BinaryOperation(MatrixProcessors::MultiplyMatrix {}, mat_int2);

    Matrix<int, 1, 4> expected_result = { 38, 44, 50, 56 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_multiply_mat_int_3_3_mat_int_3_2()
    {
    std::cout << " >>> test_multiply_mat_int_3_3_mat_int_3_2()\t\t";
    Matrix<int, 3, 3> mat_int1({ 1, 2, 3,
                                 4, 5, 6,
                                 7, 8, 9 });

    Matrix<int, 3, 2> mat_int2({ 1, 4,
                                 2, 5,
                                 3, 6 });

    auto mat_result = mat_int1.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, mat_int2);

    Matrix<int, 3, 2> expected_result = { 14, 32,
                                          32, 77,
                                          50, 122 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }



  void test_multiply_mat_int_3_4_mat_int_4_1()
    {
    std::cout << " >>> test_multiply_mat_int_3_4_mat_int_4_1()\t\t";
    Matrix<int, 3, 4> mat_int1({ 1, 2,  3,  4,
                                 5, 6,  7,  8,
                                 9, 10, 11, 12 });

    Matrix<int, 4, 1> mat_int2({ 1,
                                 2,
                                 3,
                                 4 });

    auto mat_result = mat_int1.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, mat_int2);

    Matrix<int, 3, 1> expected_result = { 30,
                                          70,
                                          110 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    } 



  void test_multiply_mat_int_4_4_mat_float_4_4()
    {
    std::cout << " >>> test_multiply_mat_int_4_4_mat_float_4_4()\t\t";
    Matrix<int, 4, 4> mat_int({ 1,  2,  3,  4,
                                5,  6,  7,  8,
                                9,  10, 11, 12,
                                13, 14, 15, 16 });
    
    Matrix<float, 4, 4> mat_float({ 1.5,  2,  3,  4,
                                    5,    6,  7,  8,
                                    9,    10, 11, 12, 
                                    13,   14, 15, 16 });
   
    auto mat_result = mat_int.BinaryOperation(MatrixProcessors::MultiplyMatrix{}, mat_float);

    Matrix<float, 4, 4> expected_result = { 90.5,  100, 110, 120,
                                            204.5, 228, 254, 280,
                                            318.5, 356, 398, 440,
                                            432.5, 484, 542, 600 };

    expected_result != mat_result ? std::cout << "...FAILED !!!" : std::cout << "...PASSED";
    std::cout << "\n";
    }

  }

