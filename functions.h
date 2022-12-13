#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}

	void initBall(sf::CircleShape & ball, const sf::Color ballColor, const sf::Vector2f ballPosition)
	{
		ball.setRadius(ballRadius);
		ball.setFillColor(ballColor);
		ball.setPosition(ballPosition);
}
