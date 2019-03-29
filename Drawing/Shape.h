#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct Record
{
	int colorNum;
	Vector2f pos;
	ShapeEnum shape;
};

// base class for shpaes
class DrawingShape
{
public:
	Vector2f position;
	Color color;
	ShapeEnum shape;
	DrawingShape(Vector2f l, Color c, ShapeEnum s)
	{
		position = l;
		color = c;
		shape = s;
	}
	virtual void draw(RenderWindow &w) = 0;
	virtual Record getFileRecord() = 0;
};

// square derieved from drawshape
class Square : public DrawingShape
{
public:
	RectangleShape newSquare;
	Square(Vector2f l, Color c, ShapeEnum s) : DrawingShape(l, c, s)
	{
		newSquare.setPosition(l);
		newSquare.setOutlineColor(c);
		newSquare.setOutlineThickness(2);
		newSquare.setSize(Vector2f(20, 20));
		newSquare.setFillColor(c);
		newSquare.setFillColor(c);
	}
	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
	Record getFileRecord()
	{
		Record temp;
		Color tempColor = newSquare.getFillColor();
		temp.colorNum = tempColor.toInteger();
		temp.pos = newSquare.getPosition();
		temp.shape = SQUARE;

		return temp;
	}
};

// circle derived from drawshape
class Circle : public DrawingShape
{
public:
	CircleShape newCircle;
	Circle(Vector2f l, Color c, ShapeEnum s) : DrawingShape(l, c, s)
	{
		newCircle.setPosition(l);
		newCircle.setRadius(10);
		newCircle.setOutlineThickness(2);
		newCircle.setOutlineColor(c);
		newCircle.setFillColor(c);
	}
	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
	}
	Record getFileRecord()
	{
		Record temp;
		Color tempColor = newCircle.getFillColor();
		temp.colorNum = tempColor.toInteger();
		temp.pos = newCircle.getPosition();
		temp.shape = CIRCLE;

		return temp;
	}
};

