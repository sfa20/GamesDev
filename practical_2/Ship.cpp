#include "Ship.h";
#include "Game.h"
using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//define the ship deconstructor
//although we set this to pure virtual, we still have to define it
Ship::~Ship() = default;

Invader::Invader() : Ship() {}

bool Invader::direction;
float Invader::speed;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
	Invader::speed = 20.f;
	
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);
	//Invader::direction = false;
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gamewidth - 16) || (!direction && getPosition().x < 116))
	{
		direction = !direction;
		move(dt * (direction) * speed, 0);
		for (int i = 0; i < ships.size(); ++i)
		{
			ships[i]->move(0, 24);
		}
	}
}