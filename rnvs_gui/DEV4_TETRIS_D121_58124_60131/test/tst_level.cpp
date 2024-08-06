#include <catch2/catch_test_macros.hpp>
#include "../src/Model/Level.h"


TEST_CASE("Test of Level") {
    model::Level level (1);

    /**
     * =========================
     * @brief REQUIRE
     * ========================
     */

    SECTION("Level is correctly 0"){
        REQUIRE(level.get_level() == 1);
    }

    SECTION("Level 0 (1) is correctly 1 seconde"){
        REQUIRE(level.get_time_in_seconde() == 1);
    }

    SECTION("Level is correctly increment to 2"){
          level.next_level(); // cette appel n'existe que dans se scope
        REQUIRE(level.get_level() == 2);
    }

    /**
     * =========================
     * @brief REQUIRE_FALSE
     * ========================
     */

    SECTION("Level is correctly 0"){
        REQUIRE_FALSE(level.get_level() == 0);
    }

    SECTION("Level is correctly 0"){
        REQUIRE_FALSE(level.get_level() == 2);
    }



}
