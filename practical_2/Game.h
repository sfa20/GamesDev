#pragma once
#include <SFML\Graphics.hpp>

constexpr uint16_t gamewidth = 800;
constexpr uint16_t gameheight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;
std::vector<Ship *> ships;


extern sf::Texture spritesheet;

