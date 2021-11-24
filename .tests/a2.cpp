#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a2.h"

TEST_CASE("a2: Example", "[task:a2]") {
    string test = "3 + 5\n"
                  "1 - 3\n"
                  "17 * 9";
    string expected = "3 + 5 = 8\n"
                      "1 - 3 = -2\n"
                      "17 * 9 = 153";
    ofstream of("input.txt");
    of << test;
    of.close();
    MathematicalOperation mo("input.txt");
    mo.Solve();
    ifstream ifs("input.txt");
    string actual, tmp;
    while (getline(ifs, tmp)) {
        actual += tmp + "\n";
    }
    expected = trim(expected);
    actual = trim(actual);
    REQUIRE(expected == actual);
}