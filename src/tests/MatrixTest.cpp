#include "Matrix.h"
#include <gtest/gtest.h>

TEST(CreateMatrixTest, CreateEmptyMatrix)
{
    MathLibrary::Matrix<2, 2> m;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            EXPECT_EQ(m.get(i, j), 0);
        }
    }
}