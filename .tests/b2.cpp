#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b2.h"

#include <string>

using namespace std;

TEST_CASE("b2: Example", "[task:b2]") {
    Number n1(4);
    Number n2(0);
    Number n3 = n1.Add(n1);
    REQUIRE(n3.GetData() == 8);
    string result = PrintDivisionResult(n1, n2);
    REQUIRE(result == "divide by zero");
}