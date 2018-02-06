#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	void Update(const float &dt);
	Bullet(const sf::Vector2f &pos, const bool mode);
	~Bullet() = default;
protected:
	sf::IntRect _sprite;
	
	//static unsigned char bulletPointer;
	//static Bullet bullets[256];
	
	//Called by the static Update()
	void _Update(const float &dt);
	//Never called by our code
	Bullet();
	//false=player bullet, true=Enemy bullet
	bool _mode;
};


extern std::vector<Bullet *> bullets;



