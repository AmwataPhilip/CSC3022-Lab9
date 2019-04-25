/**
 See vec.h for instructions
*/
#include <string>
#include "vec.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Untemplated vecN",""){
	vecN_double v(5);
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        v[3] = 4;
        v[4] = 5;
        vecN_double r = v + v;
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
        REQUIRE(v[3] == 4);
        REQUIRE(v[4] == 5);
        REQUIRE(r[0] == 2);
        REQUIRE(r[1] == 4);
        REQUIRE(r[2] == 6);
        REQUIRE(r[3] == 8);
        REQUIRE(r[4] == 10);
}

/////////////////////// TASK 1 //////////////////////////

TEST_CASE("Templeting vecN",""){
	vecN<int,5> v;
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	vecN<int,5> r = v + v;
	REQUIRE(v[0] == 1);
	REQUIRE(v[1] == 2);
	REQUIRE(v[2] == 3);
	REQUIRE(v[3] == 4);
	REQUIRE(v[4] == 5);
	REQUIRE(r[0] == 2);
	REQUIRE(r[1] == 4);
	REQUIRE(r[2] == 6);
	REQUIRE(r[3] == 8);
	REQUIRE(r[4] == 10);

}
/////////////////////// TASK 2 //////////////////////////
TEST_CASE("Partial specializing vecN to work with strings",""){
	vecN<std::string,5> v;
	v[0] = "1.000000";
	v[1] = "2.000000";
	v[2] = "3.250000";
	v[3] = "4.000000";
	v[4] = "5.000000";
	vecN<std::string,5> r = v + v;
	REQUIRE(v[0] == "1.000000");
	REQUIRE(v[1] == "2.000000");
	REQUIRE(v[2] == "3.250000");
	REQUIRE(v[3] == "4.000000");
	REQUIRE(v[4] == "5.000000");
	REQUIRE(r[0] == "2.000000");
	REQUIRE(r[1] == "4.000000");
	REQUIRE(r[2] == "6.500000");
	REQUIRE(r[3] == "8.000000");
	REQUIRE(r[4] == "10.000000");	
}
/////////////////////// TASK 3 //////////////////////////
TEST_CASE("Partial specializing vecN as a 3 dimensional vector with cross product",""){
	vecN<int,3> u;
        u[0] = 1;
        u[1] = 2;
        u[2] = 3;

        vecN<int,3> r = u * u; //cross product of two perpendicular vectors should result in the 0 vector 
        REQUIRE(u[0] == 1);
        REQUIRE(u[1] == 2);
        REQUIRE(u[2] == 3);
        REQUIRE(r[0] == 0);
        REQUIRE(r[1] == 0);
        REQUIRE(r[2] == 0);
}
