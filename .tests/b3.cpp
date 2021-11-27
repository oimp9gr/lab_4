#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b3.h"

using namespace std;

#define list util::ForbiddenList

TEST_CASE("b3: Example", "[task:b3]") {
    List lst;
    lst.PushBack(10);
    lst.PushFront(8);
    lst.Insert(1, 9);
    string result = util::trim(lst.Print());
    REQUIRE(result == "8 9 10");
}