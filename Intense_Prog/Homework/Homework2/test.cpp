#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "Counter.hpp"
#include <algorithm>
#include "iostream"

using namespace std;

vector<int> t1 = {10,20,20,30,30,30,50,70,70,70};
vector<string> t2 = {"aa","aa","aa","bb","bb","cc","cc","dd","dd","dd","ee"};

Counter<int> a;
Counter<int> b(t1);
Counter<string> b1(t2);

TEST_CASE("Constructors"){
  SECTION("Empty") {
  REQUIRE(a.Count() == 0);
  }

  SECTION("Pre set vector of ints") {
  REQUIRE(b.Count() == 10);
  }

  SECTION("Pre set vector of strings") {
  REQUIRE(b1.Count() == 11);
  }

}

TEST_CASE("Count"){

  SECTION("Count() default constructor") {
  REQUIRE(a.Count() == 0);
  }

  SECTION("Count(key) no value in map") {
  REQUIRE(b.Count(100) == 0);
  }

  SECTION("Count(key) int") {
  REQUIRE(b.Count(20) == 2);
  }

  SECTION("Count(min, max) int") {
  REQUIRE(b.Count(9,31) == 6);
  }

  SECTION("Count(key) string") {
  REQUIRE(b1.Count("cc") == 2);
  }

  SECTION("Count(min, max) string") {
  REQUIRE(b1.Count("aa","cc") == 5);
  }

}


TEST_CASE("Remove"){

  SECTION("Remove(T key) with no value that exists in map") {
    b.Remove(800);
  REQUIRE(b.Count(800) == 0);
  }

  SECTION("Remove(T key) int") {
    b.Remove(50);
  REQUIRE(b.Count(50) == 0);
  }

  SECTION("Remove(T key) string") {
    b1.Remove("ee");
  REQUIRE(b1.Count("ee") == 0);
  }
}

TEST_CASE("Incriment"){

  SECTION("Incriment T key int that doesn't exist") {
    b.Increment(40);
  REQUIRE(b.Count(40) == 1);
  }

  SECTION("Incriment T key string dd by 1") {
    b1.Increment("dd");
  REQUIRE(b1.Count("dd") == 4);
  }

  SECTION("Incriment T key 40 by int 4") {
    b.Increment(40,4);
  REQUIRE(b.Count(40) == 5);
  }

  SECTION("Incriment T key cc by int 2") {
    b1.Increment("cc",2);
  REQUIRE(b1.Count("cc") == 4);
  }

}


TEST_CASE("Decrement"){

  SECTION("Decrement T key int") {
    b.Decrement(40);
  REQUIRE(b.Count(40) == 4);
  }

  SECTION("Decrement T key string") {
    b1.Decrement("cc");
  REQUIRE(b1.Count("cc") == 3);
  }

  SECTION("Decrement T key 70 by int more than size") {
    b.Decrement(70,4);
  REQUIRE(b.Count(70) == 0);
  }

  SECTION("Incriment T key aa by int 2") {
    b1.Decrement("aa",2);
  REQUIRE(b1.Count("aa") == 1);
  }

}


TEST_CASE("MostCommon"){
  SECTION("MostCommon() int") {
    int test = b.MostCommon();
  REQUIRE(test == 40);
  }

  SECTION("MostCommon() string") {
    string test1 = b1.MostCommon();
  REQUIRE(test1 == "dd");
  }

  SECTION("MostCommon int n greater than size of map") {
    std::vector<int> most_comm_ints = b.MostCommon(10);
  REQUIRE(most_comm_ints[0] == 40);
  }

  SECTION("MostCommon string top 3") {
    std::vector<string> most_comm_strs = b1.MostCommon(3);
  REQUIRE(most_comm_strs[1] == "cc");
  }

}


TEST_CASE("LeastCommon"){
  SECTION("LeastCommon() int") {
    int lc_int = b.LeastCommon();
  REQUIRE(lc_int == 10);
  }

  SECTION("LeastCommon() string") {
    string lc_str = b1.LeastCommon();
  REQUIRE(lc_str == "aa");
  }

  SECTION("LeastCommon int top 2 ") {
    std::vector<int> lc_int_n = b.LeastCommon(2);
  REQUIRE(lc_int_n[1] == 20);
  }

  SECTION("LeastCommon string top 5 which is greater than the size ") {
    std::vector<string> lc_string_n = b1.LeastCommon(5);
  REQUIRE(lc_string_n[2] == "cc");
  }

}

TEST_CASE("Normalized"){
  SECTION("Normalized() int") {
    std::map<int,double> norm_ints = b.Normalized();
    std::pair<int, double> norm_ints_ind;
    for (std::pair<int, double> pair : norm_ints) {
      norm_ints_ind = pair;
      }
      REQUIRE(norm_ints_ind.second == 0.4);
    }

    SECTION("Normalized() strings") {
      std::map<string,double> norm_str = b1.Normalized();
      std::pair<string,double> norm_str_ind;
      for (std::pair<string, double> pair : norm_str) {
        norm_str_ind = pair;
        }
        REQUIRE(norm_str_ind.second == 0.4);
      }

  }


  TEST_CASE("Keys"){
    SECTION("Keys ints") {
      std::set<int> int_keys = b.Keys();
    REQUIRE(int_keys.find(30) != int_keys.end());
    }

    SECTION("Keys strings") {
      std::set<string> str_keys = b1.Keys();
    REQUIRE(str_keys.find("dd") != str_keys.end());
    }
  }

  TEST_CASE("Values"){
    SECTION("Values ints") {
      std::vector<int> int_vals = b.Values();
    REQUIRE(int_vals[2] == 3);
    }

    SECTION("Values strings") {
      std::vector<int> str_vals = b1.Values();
    REQUIRE(str_vals[3] == 4);
    }
  }
