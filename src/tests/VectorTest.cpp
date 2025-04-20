#include "Vector.h"
#include <gtest/gtest.h>        

TEST(VectorTest, CreateEmptyVector) {
    MathLibrary::Vector v = MathLibrary::Vector(2);
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(v.get(i), 0);
    }
}