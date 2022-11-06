#include <limits.h>
#include <stdexcept>
#include "../../Unit/Human.h"
#include "../../Country/Country.h"
#include "gtest/gtest.h"

namespace {
    TEST(MoralTest, TestMoral100) {

        Country* country = new Country("Sandton", 22);

        Human human(100, 100, 10, country, true);

        EXPECT_EQ(100, human.getMoral());

        delete country;
    }
}