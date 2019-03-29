#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Shape.h"
 
using namespace std;
using namespace sf;

class ShapeMgr
{
private:

public:
	vector <DrawingShape*> vec;

	ShapeMgr()
	{
	}

	void addShape(Vector2f pos, ShapeEnum shapeChoice, Color color)
	{
		if (shapeChoice == SQUARE)
		{
			Square* square;

			square = new Square(pos, color, shapeChoice);
			vec.push_back(square);
		}
		if (shapeChoice == CIRCLE)
		{
			Circle* circle;

			circle = new Circle(pos, color, shapeChoice);
			vec.push_back(circle);
		}		
	}
};