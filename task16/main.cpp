#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include "decorator.h"

using namespace std;

TEST_CASE("Circle")
{
	Circle c1{ 3 };
	REQUIRE(c1.str() == "A circle of radius 3");

	Circle c2{ 4 };
	REQUIRE(c2.str() == "A circle of radius 4");
}

TEST_CASE("Square")
{
	Square s1{ 3 };
	REQUIRE(s1.str() == "A square of with side 3");

	Square s2{ 4 };
	REQUIRE(s2.str() == "A square of with side 4");
}

TEST_CASE("Colred Circle")
{
	Circle c1{ 3 };
	ColoredShape red_circle{c1, "red"};
	REQUIRE(red_circle.str() == "A circle of radius 3 has the color red");

	Circle c2{ 4 };
	ColoredShape green_circle{ c2, "green" };
	REQUIRE(green_circle.str() == "A circle of radius 4 has the color green");

}

TEST_CASE("Colored Square")
{
	Square s1{ 3 };
	ColoredShape red_square{ s1, "red" };
	REQUIRE(red_square.str() == "A square of with side 3 has the color red");

	Square s2{ 4 };
	ColoredShape green_square{ s2, "green" };
	REQUIRE(green_square.str() == "A square of with side 4 has the color green");
}

TEST_CASE("Transparent Circle")
{
	Circle c1{ 3 };
	ColoredShape red_circle{ c1, "red" };
	TransparentShape tr_red_circle{ red_circle, 128 };
	REQUIRE(tr_red_circle.str() == "A circle of radius 3 has the color red has 50.1961% transparency");

	Circle c2{ 4 };
	TransparentShape tr_circle{ c2, 128 };
	REQUIRE(tr_circle.str() == "A circle of radius 4 has 50.1961% transparency");

}

void wrapper()
{
  Circle circle{ 5 };
  cout << circle.str() << endl;

  ColoredShape red_circle{ circle, "red" };
  cout << red_circle.str() << endl;

  TransparentShape red_half_visible_circle{ red_circle, 128 };
  cout << red_half_visible_circle.str() << endl;
}

int main(int argc, char* argv[])
{
  //wrapper();

  int result = Catch::Session().run(argc, argv);
  getchar();
  return result;
}
