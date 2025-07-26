#include "Matrix.h"
#include <gtest/gtest.h>

TEST(CreateMatrixTest, CreateEmptyMatrix) {
  MathLibrary::Matrix m(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(m.get(i, j), 0);
    }
  }
};

class MatrixTest : public testing::Test {
protected:
  MathLibrary::Matrix m;
  MathLibrary::Matrix v;
  float eps;

  MatrixTest() : m(2, 3), v(3, 1) {
    eps = 0.0001;
    m.set(0, 0, 7.0);
    v.set(0, 0, 1.0);
    v.set(0, 0, 1.0);
  }
};

TEST_F(MatrixTest, ModifyMatrixTest) {
  EXPECT_EQ(m.get(0, 0), 7.0);
  EXPECT_EQ(m.get(0, 1), 0.0);
  EXPECT_EQ(m.get(1, 0), 0.0);
  EXPECT_EQ(m.get(0, 1), 0.0);

  m.set(1, 1, 3.0);

  EXPECT_EQ(m.get(1, 1), 3.0);
}

TEST_F(MatrixTest, TransposeAndMultiplyTest) {

  // Create transpose and multiply with original
  auto m_prime = m.transpose();
  auto mm = m_prime * m;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 0 && j == 0) {
        EXPECT_NEAR(mm.get(i, j), 49.0, eps);
      } else {
        EXPECT_NEAR(mm.get(i, j), 0.0, eps);
      }
    }
  }

  // Multiply m with v
}