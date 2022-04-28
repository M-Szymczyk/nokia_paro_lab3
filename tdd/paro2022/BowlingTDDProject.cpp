#include "catch/catch.hpp"
#include "BowlingGame.h"

class SimpleCalculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

TEST_CASE("SimpleCalculator_add_test") {
    SimpleCalculator testObj;

    REQUIRE( testObj.add(2, 2) == 4);
    REQUIRE( testObj.add(2, 4) == 6);
}

TEST_CASE("bowlingGetOnePoint") {
    BowlingGame testObj;
    testObj.roll(1);
    REQUIRE( testObj.getScore() == 1);
}


TEST_CASE("bowlingSpare") {
    BowlingGame testObj;
    testObj.roll(6);
    testObj.roll(4);
    testObj.roll(5);
    REQUIRE( testObj.getScore() == 20);
    testObj.roll(3);
    REQUIRE( testObj.getScore() == 23);
}

TEST_CASE("bowlingStrike") {
    BowlingGame testObj;
    testObj.roll(10);
    testObj.roll(0);
    testObj.roll(1);
    REQUIRE( testObj.getScore() == 12);
    testObj.roll(4);
    REQUIRE( testObj.getScore() == 16);
}
TEST_CASE("bowlingEndGameOnly1") {
    BowlingGame testObj;
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);

    REQUIRE( testObj.getScore() == 20);
}

TEST_CASE("bowlingEndGameOnly1andlast9extra0") {
    BowlingGame testObj;
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(9);
    testObj.roll(0);
    REQUIRE( testObj.getScore() == 28);
}

TEST_CASE("bowlingEndGameOnly1andlast9extra6") {
    BowlingGame testObj;
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(1);
    testObj.roll(1);    testObj.roll(9);
    testObj.roll(6);
    REQUIRE( testObj.getScore() == 34);
}
TEST_CASE("bowlingEndGameOnly10") {
    BowlingGame testObj;
    for(int i=0;i<10;i++)
    testObj.roll(10);
//    testObj.roll(10);
//    testObj.roll(10);
    REQUIRE( testObj.getScore() == 270);
}

TEST_CASE("bowlingOnly0") {
    BowlingGame testObj;
    for(int i=0;i<20;i++)
        testObj.roll(0);
    REQUIRE( testObj.getScore() == 0);
}

TEST_CASE("bowlingOnlySpare") {
    BowlingGame testObj;
    for(int i=0;i<10;i++) {
        testObj.roll(1);
        testObj.roll(9);
    }
    REQUIRE( testObj.getScore() == 190);
}


TEST_CASE("treeStrikes") {
    BowlingGame testObj;
    for(int i=0;i<3;i++) {
        testObj.roll(10);

    }
    REQUIRE( testObj.getScore() == 60);
}


TEST_CASE("twoStrikes") {
    BowlingGame testObj;
    for(int i=0;i<2;i++) {
        testObj.roll(10);

    }
    testObj.roll(0);
    testObj.roll(0);
    REQUIRE( testObj.getScore() == 30);
}