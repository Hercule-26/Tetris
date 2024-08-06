#include <catch2/catch_test_macros.hpp>

#include "../src/Model/Shapes/Shape.h"
#include "../src/Model/Shapes/Shapes.h"
#include "../src/Model/Colors.h"
TEST_CASE("Test of Shape") {
    model::shape::Shape shape = model::shape::createShape(5);

    /**
     * =========================
     * @brief REQUIRE
     * ========================
     */
    SECTION("ID equal 5"){
        REQUIRE(shape.get_id() == 5);
    }

    SECTION("Shape correctly move"){
        REQUIRE(shape.get_offset().get_x() == 0);
        REQUIRE(shape.get_offset().get_y() == 3);
        shape.move(1,2);
        REQUIRE(shape.get_offset().get_x() == 1);
        REQUIRE(shape.get_offset().get_y() == 5);
    }

    SECTION("Shape correctly rotate"){
        REQUIRE(shape.get_cell_status()[0].get_x() == 0);
        REQUIRE(shape.get_cell_status()[0].get_y() == 1);
        shape.rotate(model::ROTATE_RIGHT);
        REQUIRE(shape.get_cell_status()[0].get_x() == 1);
        REQUIRE(shape.get_cell_status()[0].get_y() == 3);
    }
    /**
     * =========================
     * @brief REQUIRE_THROWS
     * ========================
     */
    SECTION("ID greater than 7"){
        REQUIRE_THROWS(shape.set_id(10));
    }



}
