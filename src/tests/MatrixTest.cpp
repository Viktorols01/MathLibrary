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
};

class MatrixTest : public testing::Test {
    protected:

    MatrixTest() {
        m.set(0, 0, 7.0);
        v.set(0, 0, 1.0);
        v.set(0, 0, 1.0);
    }

    MathLibrary::Matrix<2, 3> m;
    MathLibrary::Matrix<3, 1> v;
};

TEST_F(MatrixTest, ModifyMatrixTest) {
    EXPECT_EQ(m.get(0, 0), 7.0);    
    EXPECT_EQ(m.get(0, 1), 0.0);    
    EXPECT_EQ(m.get(1, 0), 0.0);    
    EXPECT_EQ(m.get(0, 1), 0.0);    
    
    m.set(1, 1, 3.0);

    EXPECT_EQ(m.get(1, 1), 3.0);    
}

TEST_F(MatrixTest, OperationsMatrixTest) {
    
    // Create transpose and multiply with original
    auto m_prime = m.transpose();
    auto mm = m_prime*m;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0) {
                EXPECT_EQ(m.get(i, j), 7.0);
            } else {
                EXPECT_EQ(m.get(i, j), 0.0); // Won't work due to precision of float
            }
        }
    }
    
    
    // Multiply m with v


}