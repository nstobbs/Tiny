#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Tiny/Vector.h"

using namespace Tiny;

TEST_CASE("Test Adding Vectors") {

    /* Test Vec2f */
    CHECK(add(Vec2f(1.5f, 2.0f), Vec2f(1.0f, 1.0f)) == Vec2f(2.5f, 3.0f));

    /* Test Vec3f */
    CHECK(add(Vec3f(3.0f, 2.0f, 3.0f), Vec3f(1.0f, 1.0f, 1.0f)) == Vec3f(4.0f, 3.0f, 4.0f));

    /* Test Vec4f */
    CHECK(add(Vec4f(3.0f, 2.0f, 3.0f, 2.0f), Vec4f(1.0f, 1.0f, 1.0f, 1.0f)) == Vec4f(4.0f, 3.0f, 4.0f, 3.0f));
};