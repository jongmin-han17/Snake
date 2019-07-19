#pragma once
#include <SFML/Graphics.hpp>

class Circle : public sf::CircleShape
{
public:
	Circle(float radius);
	virtual ~Circle();
	sf::Vector2f GetCenterPosition();
	void SetCenterPosition(float x, float y);
};