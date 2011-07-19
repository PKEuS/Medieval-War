#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <stdexcept>


class FileNotFoundException : public std::runtime_error
{
public:
	FileNotFoundException(const std::string& filename);
};

namespace sf
{
class Image;
class SoundBuffer;
class Music;
class Font;
}

class Resource
{
public:
	Resource();
	~Resource();

	//Loads a resource. Specialized for the different kinds of resources.
	//	path: Path of the resource to be loaded
	template<typename T>
	void Load(const std::string& path);

	//Returns a reference to the resource. Specialized for the different kinds of resources
	template<typename T>
	T& Get() const;
private:
	enum Type
	{
		NONE, IMAGE, SOUND, MUSIC, FONT
	} myType;
	union
	{
		sf::Image* myImage;
		sf::SoundBuffer* mySound;
		sf::Music* myMusic;
		sf::Font* myFont;
	};
};

class Resourcemanager
{
public:
	Resourcemanager() {}

	//Returns a reference to the resource object. Takes the type of the resource as template parameter. If the resource object is not already loaded from file, it is loaded
	//	path: Path of the resource
	template<typename T>
	T& Get(const std::string& path);
private:
	std::map<std::string, Resource> myResources;
};

#include "Resourcemanager.inl"

#endif
