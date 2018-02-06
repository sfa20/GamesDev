#include "Bullet.h"
#include "game.h"
#include "Ship.h"
using namespace sf;
using namespace std;


//Create definition for the constructor
Bullet::Bullet(const sf::Vector2f &pos, const bool mode) : Sprite()
{
	_sprite = IntRect(64, 32, 32, 32);
	setTexture(spritesheet);
	setTextureRect(_sprite); 
	setPosition(pos.x, pos.y);

}

void Bullet::Update(const float &dt)
{
	move(0, dt * 200.f * (_mode ? -1.0f : 1.0f));
}




