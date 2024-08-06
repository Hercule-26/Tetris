#include <catch2/catch_test_macros.hpp>
#include "../src/Model/Shapes/Position.h"


TEST_CASE("Test of Position") {
    model::shape::Position position(1,2);

    /**
     * =========================
     * @brief REQUIRE
     * ========================
     */
    SECTION("correct x"){
        REQUIRE(position.get_x() == 1);
    }
    SECTION("correct y"){
        REQUIRE(position.get_y() == 2);
    }

    /**
     * =========================
     * @brief REQUIRE_FALSE
     * ========================
     */
    SECTION("wrong y"){
        REQUIRE_FALSE(position.get_y() == 3);
    }

    SECTION("wrong x"){
        REQUIRE_FALSE(position.get_x() == 10);
    }
}
