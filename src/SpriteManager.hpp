#ifndef SPRITEMANAGER_HPP
#define SPRITEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>


class SpriteManager
{
public:
	void AddImage(std::string file);
	void AddSprite(std::string file, std::string name);
	void AddSprite(std::string file, std::string name, sf::IntRect subRect);
	sf::Sprite* GetSprite(std::string name);
	
private:
	void UpdateSprites();
	std::map<std::string, sf::Image> myImages;
	std::map<std::string, sf::Sprite> mySprites;
	std::map<std::string, std::string> mySpriteSource;
};

#endif
