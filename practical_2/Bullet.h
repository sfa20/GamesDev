#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	Bullet(const sf::Vector2f &pos, const bool mode);
	~Bullet() = default;

	//Updates all bullets
	//static void Update(const float &dt);
	////Renders all bullets
	//static void Render(sf::RenderWindow &window);
	//choose an inactive bullet and use it
	//static Fire(const sf::Vector2f &pos, const bool mode);

	~Bullet() = default;
protected:
	sf::IntRect _sprite;
	static unsigned char bulletPointer;
	static Bullet bullets[256];
	//Called by the static Update()
	void _Update(const float &dt);
	//Never called by our code
	Bullet();
	//false=player bullet, true=Enemy bullet
	bool _mode;
};


