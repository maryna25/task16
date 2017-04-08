#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Shape
{
	virtual string str() const = 0;
};

struct Circle : Shape
{
	float radius;

	Circle(){}

	explicit Circle(const float radius)
		: radius{ radius }
	{
	}

	string str() const override
	{
		ostringstream oss;
		oss << "A circle of radius " << radius;
		return oss.str();
	}
};

struct Square : Shape
{
	float side;

	Square(){}

	explicit Square(const float side)
		: side{ side }
	{
	}

	string str() const override
	{
		ostringstream oss;
		oss << "A square of with side " << side;
		return oss.str();
	}
};

struct ColoredShape : Shape
{
	Shape& shape;
	string color;

	ColoredShape(Shape& shape, const string& color1)
		: shape{ shape }
	{
		color = color1;
	}

	string str() const override
	{
		ostringstream oss;
		oss << shape.str() << " has the color " << color;
		return oss.str();
	}
};

struct TransparentShape : Shape
{
	Shape& shape;
	int transparency;


	TransparentShape(Shape& shape, const int transparency)
		: shape{ shape },
		transparency{ transparency }
	{
	}

	string str() const override
	{
		ostringstream oss;
		oss << shape.str() << " has "
			<< static_cast<float>(transparency) / 255.f*100.f
			<< "% transparency";
		return oss.str();
	}
};
