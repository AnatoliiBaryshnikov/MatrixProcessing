#include <iostream>
#include <array>
#include "Matrix.h"
#include "MatrixProcessors.h"
#include "Test.h"

int main()
{
    Tests::run_all_automatic_tests();
    Tests::test_console_output();

    system("pause");
}

