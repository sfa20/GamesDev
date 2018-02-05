#include "player.h"
using namespace sf;
using namespace std;

void Player::update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		setPosition(Vector2f(getPosition().x - _speed, getPosition().y));
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		setPosition(Vector2f(getPosition().x + _speed, getPosition().y));
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		setPosition(Vector2f(getPosition().x, getPosition().y - _speed));
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		setPosition(Vector2f(getPosition().x , getPosition().y + _speed));
	}

	Entity::update(dt);
}

Player::Player() : _speed(0.1f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(-25.f, -25.f));
	setPosition(Vector2f(-25.f, -25.f));
}


void Player::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}