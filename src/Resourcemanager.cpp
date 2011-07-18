#include "Resourcemanager.hpp"

FileNotFoundException::FileNotFoundException(const std::string& filename) :
std::runtime_error("File not found: " + filename)
{
}

// Resource
Resource::Resource()
	: myType(NONE)
{
}

template<>
void Resource::Load<sf::Image>(const std::string& path)
{
	if(myType == NONE)
	{
		myType = IMAGE;
		myImage = new sf::Image();
		if(!myImage->LoadFromFile(path))
			throw(FileNotFoundException(path));
	}
}
template<>
void Resource::Load<sf::SoundBuffer>(const std::string& path)
{
	if(myType == NONE)
	{
		myType = SOUND;
		mySound = new sf::SoundBuffer();
		if(!mySound->LoadFromFile(path))
			throw(FileNotFoundException(path));
	}
}
template<>
void Resource::Load<sf::Font>(const std::string& path)
{
	if(myType == NONE)
	{
		myType = FONT;
		myFont = new sf::Font();
		if(!myFont->LoadFromFile(path))
			throw(FileNotFoundException(path));
	}
}

template<>
sf::Image& Resource::Get<sf::Image>() const
{
	if(myType != IMAGE) throw std::logic_error("You tried to load an image from a resource which is no image.");
	return *myImage;
}
template<>
sf::SoundBuffer& Resource::Get<sf::SoundBuffer>() const
{
	if(myType != SOUND) throw std::logic_error("You tried to load a sound from a resource which is no sound.");
	return *mySound;
}
template<>
sf::Font& Resource::Get<sf::Font>() const
{
	if(myType != FONT) throw std::logic_error("You tried to load a font from a resource which is no font.");
	return *myFont;
}

Resource::~Resource()
{
	switch(myType)
	{
		case IMAGE:
			delete myImage;
			break;
		case SOUND:
			delete mySound;
			break;
		case FONT:
			delete myFont;
			break;
		default:
			break;
	}
}
