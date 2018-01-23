#include "Ship.h"
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


//Invader Class details

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

	if ((direction && getPosition().x > gamewidth - 16) || (!direction && getPosition().x < 16))
	{
		direction = !direction;
		move(dt * (direction) * speed, 0);
		for (int i = 0; i < ships.size(); ++i)
		{
			ships[i]->move(0, 24);
		}
	}
}


Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({ gameheight * .5f, gameheight - 82.f });
	
}

void Player::Update(const float &dt) {
	Ship::Update(dt);
	float speed = 100.0f;
	setPosition({ getPosition().x, gameheight - 82.f });
	//Move Left
	if (Keyboard::isKeyPressed(Keyboard::Left) && getPosition().x > 16)
	{
		speed++;
		move(dt * (-speed), 0);
	}
	//Move Right
	if (Keyboard::isKeyPressed(Keyboard::Right) && getPosition().x < gamewidth - 16)
	{
		speed--;
		move(dt * (speed), 0);
	}
}