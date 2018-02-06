#include "Ship.h"
#include "Game.h"
#include "Bullet.h"
using namespace sf;
using namespace std;


/****************
**BASE CLASS*****
*****************/
#pragma region BaseClass

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

#pragma endregion


/**********************
*****INVADER CLASS*****
***********************/
#pragma region Invader

Invader::Invader() : Ship() {}

bool Invader::direction;
float Invader::speed;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
	//Invader::speed = 20.f;
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);
	Invader::speed = 50.0f;

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16))
	{
		direction = !direction;
		move(dt * (direction)* speed, 0);
		for (int i = 0; i < ships.size(); ++i)
		{
			ships[i]->move(0, 24);
		}
	}
}

#pragma endregion


/**********************
*****PLAYER CLASS******
***********************/
#pragma region Player

Player::Player() : Ship(IntRect(160, 32, 32, 32))
{
	setPosition(gameHeight * .5f, gameHeight - 82.f);
}

void Player::Update(const float &dt) {
	//static vector<Bullet*> bullets;

	Ship::Update(dt);

	float speed = 100.0f;
	setPosition(getPosition().x, gameHeight - 82.f);
	//Move Left
	if (Keyboard::isKeyPressed(Keyboard::Left) && getPosition().x > 16)
	{
		speed++;
		move(dt * (-speed), 0);
	}
	//Move Right
	if (Keyboard::isKeyPressed(Keyboard::Right) && getPosition().x < gameWidth - 32)
	{
		speed--;
		move(dt * (speed), 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		bullets.push_back(new Bullet(getPosition(), true));
	}

	for (const auto s : bullets) {
		s->Update(dt);
	}
}
#pragma endregion
