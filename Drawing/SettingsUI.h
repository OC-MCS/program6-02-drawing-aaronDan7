#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

class SettingsUI
{
private:
	SettingsMgr *settingsManager;
	CircleShape redBtn, blueBtn, greenBtn, circleBtn;
	RectangleShape squareBtn;
public:

	SettingsUI(SettingsMgr *mgr)
	{
		settingsManager = mgr;

		// set buttons and positions
		//Red button
		Vector2f redPos(100, 70);
		redBtn.setPosition(redPos);
		redBtn.setRadius(20);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);

		//Green button
		Vector2f greenPos(100, 140);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(20);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		//Blue button
		Vector2f bluePos(100, 210);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(20);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);

		//Circle button
		Vector2f circlePos(100, 370);
		circleBtn.setPosition(circlePos);
		circleBtn.setRadius(20);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		//Square button
		Vector2f sqPos(100, 440);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
	}

	void handleMouseUp(Vector2f mouse)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Red);
		}

		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Green);
		}

		else if (blueBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurColor(Color::Blue);
		}

		else if (circleBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurShape(ShapeEnum::CIRCLE);
		}

		else if (squareBtn.getGlobalBounds().contains(mouse))
		{
			settingsManager->setCurShape(ShapeEnum::SQUARE);
		}
	}

	void draw(RenderWindow& win)
	{
		// titles
		Font font;
		font.loadFromFile("C:\\Windows\\Fonts\\Calibri.ttf");

		Text selectedColor("Select Pen Color", font, 25);
		selectedColor.setPosition(30, 25);

		Text selectedShape("Select Pen Shape", font, 25);
		selectedShape.setPosition(30, 300);

		//switch button fills on selection
		//Red Button
		if (settingsManager->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			greenBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
		}
		
		//Green Button
		if (settingsManager->getCurColor() == Color::Green)
		{
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
		}

		// Blue Button
		if (settingsManager->getCurColor() == Color::Blue)
		{
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Blue);
		}

		// Circle Button
		if (settingsManager->getCurShape() == ShapeEnum::CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
		}

		// Square Button
		if (settingsManager->getCurShape() == ShapeEnum::SQUARE)
		{
			circleBtn.setFillColor(Color::Transparent);
			squareBtn.setFillColor(Color::White);
		}

		win.draw(selectedColor);
		win.draw(selectedShape);

		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(blueBtn);

		win.draw(circleBtn);
		win.draw(squareBtn);
	}
};
