#include "Matrix.h"
#include <gtest/gtest.h>

TEST(CreateMatrixTest, CreateEmptyMatrix) {
  MathLibrary::Matrix<int> m{2, 2};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(m.get(i, j), 0);
    }
  }
};

class MatrixTest : public testing::Test {
protected:
  MathLibrary::Matrix<int> m;
  MathLibrary::Matrix<int> v;

  MatrixTest() : m{ 2, 3 }, v{ 3, 1 } {
    m.set(0, 0, 7);
    v.set(0, 0, 1);
    v.set(0, 0, 1);
  }
};

TEST_F(MatrixTest, ModifyMatrixTest) {
  EXPECT_EQ(m.get(0, 0), 7);
  EXPECT_EQ(m.get(0, 1), 0);
  EXPECT_EQ(m.get(1, 0), 0);
  EXPECT_EQ(m.get(0, 1), 0);

  m.set(1, 1, 3);

  EXPECT_EQ(m.get(1, 1), 3);
}

TEST_F(MatrixTest, TransposeAndMultiplyTest) {

  // Create transpose and multiply with original
  auto m_prime = m.transpose();
  auto mm = m_prime * m;

  for (int i = 0; i < mm.getRowCount(); i++) {
    for (int j = 0; j < mm.getColCount(); j++) {
      if (i == 0 && j == 0) {
        EXPECT_EQ(mm.get(i, j), 49);
      } else {
        EXPECT_EQ(mm.get(i, j), 0);
      }
    }
  }

  // Multiply m with v
}

TEST_F(MatrixTest, MultiplyMatrixAndVectorTest) {
  auto mv = m * v;
  EXPECT_EQ(mv.get(0, 0), 7);
  EXPECT_EQ(mv.get(1, 0), 0);
}

TEST_F(MatrixTest, MatrixOperationsTest) {
  auto m_quadruple = (m + m) * 2;
  for (int i = 0; i < m_quadruple.getRowCount(); i++) {
    for (int j = 0; j < m_quadruple.getColCount(); j++) {
      if (i == 0 && j == 0) {
        EXPECT_EQ(m_quadruple.get(i, j), 28);
      } else {
        EXPECT_EQ(m_quadruple.get(i, j), 0);
      }
    }
  }
}