#pragma once
#include <SFML/Graphics.hpp>

extern sf::Texture waterTX_l;
extern sf::Texture waterTX_r;
extern sf::Texture waterTX_u;
extern sf::Texture waterTX_d;
extern sf::Texture obstacleTX;
extern sf::Texture holeTX;
extern sf::Texture ballTX;
extern sf::Texture obstacle64_light;

void loadTexture(sf::Texture& tex, const std::string& path);
void initializeTextures();
