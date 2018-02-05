#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
using namespace sf;
using namespace std;

Player* player = new Player();

void Load()
{
	player;

}

void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	player->update(dt);

}

void Render(RenderWindow &window)
{
	player->render(window);

}

int main() {
	RenderWindow window(VideoMode(600, 800),"Maze Game");
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

