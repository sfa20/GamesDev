#include "Bullet.h"
#include "game.h"
#include "Ship.h"
using namespace sf;
using namespace std;


//Create definition for the constructor
Bullet::Bullet(const sf::Vector2f &pos, const bool mode) : Sprite()
{
	_sprite = IntRect(120, 20, 32, 32);
	setTexture(spritesheet);
	setTextureRect(_sprite); 
	setOrigin(16, 16);

}


//void Bullet::Update(const float &dt) {
//	move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
//	
//}

void Bullet::_Update(const float &dt) {
	if (getPosition().y < -32 || getPosition().y > gameheight + 32)
	{
		//Off Screen - do nothing 
		return;
	}
	else
	{
		move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			if (!_mode && s == player) {
				//player bullets don't collide with player
				continue;
			}
			if (_mode && s != player) {
				//invader bullets don't collide with other invaders
				continue;
			}
			if (!s->is_exploded() && s->getGlobalBounds().intersect(boundingBox)) {
				//Explode the ship
				s->Explode();
				//warp bullet off-screen
				setPosition(-100, -100);
				return;
			}
		}
	}
}

Bullet::Bullet()
{
}


