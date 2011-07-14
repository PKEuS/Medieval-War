#include "SpriteManager.hpp"

void SpriteManager::AddImage(std::string file)
{
	sf::Image image;
	if(!image.LoadFromFile(file))
		exit(EXIT_FAILURE);
	std::pair<std::map <std::string, sf::Image>::iterator, bool> p;
	p = myImages.insert(std::pair <std::string, sf::Image>(file, image));
	if(!p.second)
		exit(EXIT_FAILURE);
	UpdateSprites();
}

void SpriteManager::AddSprite(std::string file, std::string name)
{
	sf::Sprite sprite;
	{
		std::map<std::string, sf::Image>::iterator i;
		i = myImages.find(file);
		if(i == myImages.end())
			exit(EXIT_FAILURE);
		sprite.SetImage(i->second);
	}
	{
		std::pair<std::map <std::string, std::string>::iterator, bool> p;
		p = mySpriteSource.insert(std::pair <std::string, std::string>(name, file));
		if(!p.second)
			exit(EXIT_FAILURE);
	}
	{
		std::pair<std::map <std::string, sf::Sprite>::iterator, bool> p;
		p = mySprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
		if(!p.second)
			exit(EXIT_FAILURE);
	}
}

void SpriteManager::AddSprite(std::string file, std::string name, sf::IntRect subRect)
{
	sf::Sprite sprite;
	{
		std::map<std::string, sf::Image>::iterator i;
		i = myImages.find(file);
		if(i == myImages.end())
			exit(EXIT_FAILURE);
		sprite.SetImage(i->second);
	}
	{
		std::pair<std::map <std::string, std::string>::iterator, bool> p;
		p = mySpriteSource.insert(std::pair <std::string, std::string>(name, file));
		if(!p.second)
			exit(EXIT_FAILURE);
	}
	sprite.SetSubRect(subRect);
	{
		std::pair<std::map <std::string, sf::Sprite>::iterator, bool> p;
		p = mySprites.insert(std::pair<std::string, sf::Sprite>(name, sprite));
		if(!p.second)
			exit(EXIT_FAILURE);
	}
}

void SpriteManager::UpdateSprites()
{
	for(std::map<std::string, sf::Sprite>::iterator i = mySprites.begin(); i != mySprites.end(); ++i)
	{
		std::map<std::string, std::string>::iterator itSpriteSource;
		itSpriteSource = mySpriteSource.find(i->first);
		if(itSpriteSource == mySpriteSource.end())
			exit(EXIT_FAILURE);
		std::map<std::string, sf::Image>::iterator itImages;
		itImages = myImages.find(itSpriteSource->second);
		if(itImages == myImages.end())
			exit(EXIT_FAILURE);
		i->second.SetImage(itImages->second);
	}
}

sf::Sprite* SpriteManager::GetSprite(std::string name)
{
	std::map<std::string, sf::Sprite>::iterator i;
	i = mySprites.find(name);
	if(i != mySprites.end())
		return &(i->second);
	return NULL;
}

