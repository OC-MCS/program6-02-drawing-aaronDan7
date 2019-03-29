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
	// draw space and window frame
	RectangleShape wholeBox;
	RectangleShape leftBox;
public:

	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draw outer border
		Vector2f sqPos(10, 10);
		wholeBox.setPosition(sqPos);
		wholeBox.setOutlineColor(Color::White);
		wholeBox.setOutlineThickness(3);
		wholeBox.setSize(Vector2f(780, 580));
		wholeBox.setFillColor(Color::Transparent);
		win.draw(wholeBox);

		// Draw left draw border for side menu
		Vector2f sqPos2(10, 10);
		leftBox.setPosition(sqPos2);
		leftBox.setOutlineColor(Color::White);
		leftBox.setOutlineThickness(3);
		leftBox.setSize(Vector2f(250, 580));
		leftBox.setFillColor(Color::Transparent);
		win.draw(leftBox);

		// Draw shapes
		for (int i = 0; i < mgr->vec.size(); i++)
		{
			mgr->vec[i]->draw(win);
		}
	}

	// no drawing while mouse is off screen
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