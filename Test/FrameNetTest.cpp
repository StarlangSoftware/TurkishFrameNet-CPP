//
// Created by Olcay Taner YILDIZ on 18.12.2020.
//

#include "catch.hpp"
#include "../src/FrameNet.h"
#include <unordered_set>

using namespace std;

TEST_CASE("FrameNetTest-testFrameSize") {
    FrameNet frameNet = FrameNet();
    REQUIRE(809 == frameNet.size());
}

TEST_CASE("FrameNetTest-testLexicalUnitSize") {
    FrameNet frameNet = FrameNet();
    int count = 0;
    for (int i = 0; i < frameNet.size(); i++){
        count += frameNet.getFrame(i).lexicalUnitSize();
    }
    REQUIRE(8493 == count);
}

TEST_CASE("FrameNetTest-testFrameElementSize") {
    FrameNet frameNet = FrameNet();
    int count = 0;
    for (int i = 0; i < frameNet.size(); i++){
        count += frameNet.getFrame(i).frameElementSize();
    }
    REQUIRE(8656 == count);
}

TEST_CASE("FrameNetTest-testDistinctFrameElements") {
    FrameNet frameNet = FrameNet();
    unordered_set<string> elements;
    for (int i = 0; i < frameNet.size(); i++){
        for (int j = 0; j < frameNet.getFrame(i).frameElementSize(); j++){
            elements.emplace(frameNet.getFrame(i).getFrameElement(j));
        }
    }
    REQUIRE(1012 == elements.size());
}
