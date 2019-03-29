#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;
public:
	// constructor for colors and shapes
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}
	// getters and setters to use them
	void setCurColor(Color setColor)
	{
		currentColor = setColor;
	}
	Color getCurColor()
	{
		return currentColor;
	}
	void setCurShape(ShapeEnum setShape)
	{
		currentShape = setShape;
	}
	ShapeEnum getCurShape()
	{
		return currentShape;
	}
};