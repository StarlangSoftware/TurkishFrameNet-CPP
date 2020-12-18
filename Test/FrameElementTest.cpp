//
// Created by Olcay Taner YILDIZ on 18.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../FrameElement.h"

TEST_CASE("FrameElement-testFrameElement") {
    FrameElement frameElement = FrameElement("Agent$Apply_Heat$TUR10-0100230");
    REQUIRE("Agent" == frameElement.getFrameElementType());
    REQUIRE("Apply_Heat" == frameElement.getFrame());
    REQUIRE("TUR10-0100230" == frameElement.getId());
    REQUIRE("Agent$Apply_Heat$TUR10-0100230" == frameElement.to_string());
}
