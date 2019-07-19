#include "Circle.h"

Circle::Circle(float radius)
	: sf::CircleShape(radius)
{
}

Circle::~Circle()
{
}

const sf::Vector2f& Circle::GetCenterPosition() const
{
	sf::Vector2f position = getPosition();

	return sf::Vector2f(position.x + getRadius(), position.y + getRadius());
}
