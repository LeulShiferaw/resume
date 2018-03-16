#include "Entity.hpp"

void Entity::setVelocity(sf::Vector2f n)
{
	mVelocity = n;
}

void Entity::setVelocity(float x, float y)
{
	mVelocity.x = x;
	mVelocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}