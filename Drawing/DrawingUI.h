#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// using namespace std;
// using namespace sf;
#include "ShapeMgr.h"
;
class DrawingUI
{
private:
	RectangleShape outerBox;
	RectangleShape leftSide;
public:

	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draw outer border
		Vector2f sqPos(10, 10);
		outerBox.setPosition(sqPos);
		outerBox.setOutlineColor(Color::White);
		outerBox.setOutlineThickness(3);
		outerBox.setSize(Vector2f(780, 580));
		outerBox.setFillColor(Color::Transparent);
		win.draw(outerBox);

		// Draw left draw border for side menu
		Vector2f sqPos2(10, 10);
		leftSide.setPosition(sqPos2);
		leftSide.setOutlineColor(Color::White);
		leftSide.setOutlineThickness(3);
		leftSide.setSize(Vector2f(250, 580));
		leftSide.setFillColor(Color::Transparent);
		win.draw(leftSide);

		// Draw shapes
		for (int i = 0; i < mgr->vec.size(); i++)
		{
			mgr->vec[i]->draw(win);
		}
	}

	// no draw when mouse is off
	bool isMouseOnWindow(Vector2f mousePos)
	{
		bool onWindow = false;
		if (mousePos.x >= 265 && mousePos.x <= 747 && mousePos.y >= 14 && mousePos.y <= 547) 
		{
			onWindow = true;
		}
		return onWindow;
	}
};