#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ship.h"
#include "Game.h"
#include "Bullet.h"

using namespace sf;
using namespace std;

 
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;
std::vector<Bullet *> bullets;

void Load()
{
	if (!spritesheet.loadFromFile("bin/invaders_sheet.png"))
	{
		cerr << "Failed to load spritesheet" << std::endl;
	}

	Player* player = new Player();
	ships.push_back(player);
	
	Vector2f position2(gameWidth / 2, gameHeight /  2);
	//auto bullet = new Bullet(position2, true);
	//bullets.push_back(bullet);

	for (int r = 0; r < invaders_rows; ++r) 
	{
		auto rect = IntRect(0,0,32,32);
		for (int c = 0; c < invaders_columns; ++c)
		{
			Vector2f position(125 + gameWidth / 18 * c, 30 + gameHeight / 18 * r);
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}
}

void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	for (auto &s : ships) {
		s->Update(dt);
	}

	for (auto &b : bullets)	{
		b->Update(dt);
	}

}

void Render(RenderWindow &window)
{
	for (const auto s : ships) {
		window.draw(*s);
	}

	for (const auto b : bullets) {
		window.draw(*b);
	}
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight),"space invaders");
	Load();
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}

