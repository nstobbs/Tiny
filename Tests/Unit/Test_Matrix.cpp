#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Tiny/Matrix.h"

using namespace Tiny;

TEST_CASE("Test Creating Identity Matrix") {
    Mat4f testMat = Identity<f32, 4, 4>();
    Mat4f expectMat;
    expectMat.data[0][0] = 1.0f;
    expectMat.data[1][1] = 1.0f;
    expectMat.data[2][2] = 1.0f;
    expectMat.data[3][3] = 1.0f;

    CHECK(testMat == expectMat);
};