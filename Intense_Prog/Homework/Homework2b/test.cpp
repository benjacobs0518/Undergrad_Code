#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Counter.hpp"

Counter<string> b;
vector<int> i = { 20, 40, 60,80 };
TEST_CASE ( "Insert", "[Counter]")
{
	SECTION( "Insert strings" )
	{
		REQUIRE(s.Insert("moose"); == 1);
    REQUIRE(s.Insert("bear"); == 1);
	}

}
