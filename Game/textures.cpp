#include "textures.h"
#include <iostream>

sf::Texture waterTX_l;
sf::Texture waterTX_r;
sf::Texture waterTX_u;
sf::Texture waterTX_d;
sf::Texture obstacleTX;
sf::Texture holeTX;
sf::Texture ballTX;
sf::Texture obstacle64_light;

void loadTexture(sf::Texture& tex, const std::string& path) {
    std::string destination = "resources/textures/" + path;
    if (!tex.loadFromFile(destination)) {
        std::cerr << "Failed to load texture from " << destination << std::endl;
    }
}

void initializeTextures() {
    loadTexture(waterTX_l, "waterTX_l.png");
    loadTexture(waterTX_r, "waterTX_r.png");
    loadTexture(waterTX_u, "waterTX_u.png");
    loadTexture(waterTX_d, "waterTX_d.png");
    loadTexture(holeTX, "holeTX.png");
    loadTexture(ballTX, "ballTX.png");
    loadTexture(obstacleTX, "obstacleTX.png");
    loadTexture(obstacle64_light, "obstacle64_light.png");
}
