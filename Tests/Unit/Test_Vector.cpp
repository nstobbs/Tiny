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

TEST_CASE("Test Subtracting Vectors") {
    /* Test Vec2f */
    CHECK(subtract(Vec2f(1.5f, 2.5f), Vec2f(0.5f, 1.0f)) == Vec2f(1.0f, 1.5f));
    /* Test Vec3f */
    CHECK(subtract(Vec3f(3.0f, 2.0f, 3.0f), Vec3f(1.0f, 1.0f, 1.0f)) == Vec3f(2.0f, 1.0f, 2.0f));
    /* Test Vec4f */
    CHECK(subtract(Vec4f(3.0f, 2.0f, 3.0f, 2.0f), Vec4f(1.0f, 1.0f, 1.0f, 1.0f)) == Vec4f(2.0f, 1.0f, 2.0f, 1.0f));
};

TEST_CASE("Test Multiplying Vectors with Scalars") {
    /* Test Vec2f */
    CHECK(multiply(Vec2f(1.5f, 2.5f), 10.0f) == Vec2f(15.0f, 25.0f));
    /* Test Vec3f */
    CHECK(multiply(Vec3f(3.0f, 2.0f, 3.0f), 2.0f) == Vec3f(6.0f, 4.0f, 6.0f));
    /* Test Vec4f */
    CHECK(multiply(Vec4f(3.0f, 2.0f, 3.0f, 2.0f), 1.0f) == Vec4f(3.0f, 2.0f, 3.0f, 2.0f));
}