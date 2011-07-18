#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <map>


class Settings
{
public:
	Settings(int argc, char* argv[]);
	~Settings();
	
	void LoadDefaults();
	void LoadConfigFile();
	int ParseArguments();
	void SaveConfigFile();
	
	const std::string& GetSettings(const std::string& section, const std::string& name) const;
	sf::VideoMode GetVideoMode() const;
	unsigned long GetWindowStyle() const;
private:
	void Help() const;
	void SetResolution(const std::string&);
	void SetDesktopResolution();
	
	int myArgc;
	char** myArgv;
	
	std::map<std::string, std::map<std::string, std::string> > mySettings;
	
	std::string WindowStyleClose;
	std::string WindowStyleFullscreen;
	std::string WindowStyleEmulation;
};


#endif // SETTINGS_HPP


