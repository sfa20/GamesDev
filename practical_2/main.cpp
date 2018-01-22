#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ship.h"
#include "Game.h"

using namespace sf;
using namespace std;

 
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;


void Load()
{
	if (!spritesheet.loadFromFile("bin/invaders_sheet.png"))
	{
		cerr << "Failed to load spritesheet" << std::endl;
	}

	
	for (int r = 0; r < invaders_rows; ++r) 
	{
		auto rect = IntRect(0,0,32,32);
		for (int c = 0; c < invaders_columns; ++c)
		{
			Vector2f position(125 + gamewidth / 18 * c, 30 + gameheight / 18 * r);
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}

	//Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 200, 200 });
	//ships.push_back(inv);
}


void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	for (auto &s : ships) {
		s->Update(dt);
	}
}


void Render(RenderWindow &window)
{
	for (const auto s : ships) {
		window.draw(*s);
	}
	window.draw(invader);
}


int main() {
	RenderWindow window(VideoMode(gamewidth, gameheight),"space invaders");
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

