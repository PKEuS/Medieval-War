#include "Settings.hpp"
#include "FileSystem.hpp"

#include <sstream>
#include <fstream>


namespace bfs = boost::filesystem;


Settings::Settings(int argc, char* argv[]) :
myArgc(argc), myArgv(argv)
{
	std::stringstream stringstream; stringstream << sf::Style::Close;
	WindowStyleClose = stringstream.str();
	stringstream.clear(); stringstream << sf::Style::Fullscreen;
	WindowStyleFullscreen = stringstream.str();
	WindowStyleEmulation = "0";
	
	LoadDefaults();
}


Settings::~Settings()
{
	SaveConfigFile();
}



void Settings::LoadDefaults()
{
	mySettings["Window"]["Width"] = "800";
	mySettings["Window"]["Height"] = "600";
	mySettings["Window"]["Style"] = WindowStyleClose;
}


void Settings::LoadConfigFile()
{
	bfs::path settingspath = FileSystem::GetGameSettingsDirectory();
	
	if(!exists(settingspath))
	{
		try
		{
			create_directory(settingspath);
		}
		catch(const bfs::filesystem_error& ex)
		{
			std::cerr << "Error while creating the settings directory:\n" << ex.what() << "\n\n";
		}
	}
	
	settingspath /= "settings.ini";
	std::ifstream file(settingspath.c_str());
	
	if(!file.fail())
	{
		std::string section;
		
		while(!file.eof())
		{
			std::getline(file, section);
			if(section[0] == '[' && section.find(']') != std::string::npos)
			{
				section = section.substr(1, section.find(']') - 1);
				std::string name;
				
				while(!file.eof())
				{
					unsigned int pos = file.tellg();
					std::getline(file, name);
					if(name[0] == '[')
					{
						file.seekg(pos);
						break;
					}
					if(name[0] != ';' && name[0] != '#' && name.size() > 0)
					{
						std::string value = name;
						name = name.substr(0, name.find('='));
						value = value.substr(value.find('=') + 1);
						
						mySettings[section][name] = value;
					}
				}
			}
		}
	}
	
	file.close();
}


int Settings::ParseArguments()
{
	for(unsigned int i = 1; i < myArgc; ++i)
	{
		std::string argument = myArgv[i];
		
		if(argument == "--fullscreen" || argument == "-full")
		{
			mySettings["Window"]["Style"] = WindowStyleFullscreen;
		}
		else if(argument == "--fullscreenemulation" || argument == "-fsemu")
		{
			mySettings["Window"]["Style"] = WindowStyleEmulation;
			SetDesktopResolution();
		}
		else if(argument == "--window" || argument == "-win")
		{
			mySettings["Window"]["Style"] = WindowStyleClose;
		}
		else if(argument == "--desktop-mode")
		{
			SetDesktopResolution();
		}
		else if(argument.substr(0,13) == "--resolution=" && argument.length() > 18)
		{
			std::string string(argument.substr(13));
			SetResolution(string);
		}
		else if(argument.substr(0,5) == "-res=" && argument.length() > 10)
		{
			std::string string(argument.substr(5));
			SetResolution(string);
		}
		else if(argument == "--help" || argument == "-h")
		{
			Help();
			return 1;
		}
		else
		{
			std::cout << myArgv[0] << ": invalid optin '" << argument << "'.\n";
			std::cout << "Try '" << myArgv[0] << " --help' to get more information." << std::endl;
			return -1;
		}
	}
	
	return 0;
}


void Settings::SaveConfigFile()
{
	bfs::path settingspath = FileSystem::GetGameSettingsDirectory();
	settingspath /= "settings.ini";
	
	std::ofstream file(settingspath.c_str(), std::ios_base::trunc);
	
	if(!file.fail())
	{
		for(std::map<std::string, std::map<std::string, std::string> >::iterator it = mySettings.begin(); it != mySettings.end(); ++it)
		{
			file << '[' << (*it).first << "]\n";
			for(std::map<std::string, std::string>::iterator it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2)
			{
				file << (*it2).first << '=' << (*it2).second << "\n";
			}
		}
	}
	else
	{
		std::cerr << "Error: Cannot write the config file " << settingspath << ".\n";
	}
	
	file.close();
}


void Settings::SetResolution(const std::string& string)
{
	mySettings["Window"]["Width"] = string.substr(0, string.find(','));
	mySettings["Window"]["Height"] = string.substr(string.find(',') + 1);
}


void Settings::SetDesktopResolution()
{
	std::stringstream sstr;
	sstr << sf::VideoMode::GetDesktopMode().Width;
	sstr >> mySettings["Window"]["Width"];
	sstr.clear(); sstr << sf::VideoMode::GetDesktopMode().Height;
	sstr >> mySettings["Window"]["Height"];
}


void Settings::Help() const
{
	std::cout << "    Medieval War - An isometric cross-platform real-time strategy game.\n\n";
	std::cout << "Arguments are:\n";
	std::cout << "\t-h\t  --help\t\t  Show this help text.\n";
	std::cout << "\t-win\t  --window\t\t  Play the game in window mode.\n";
	std::cout << "\t-full\t  --fullscreen\t\t  Play the game in fullscreen mode.\n";
	std::cout << "\t-fsemu\t  --fullscreenemulation\t  Emulate a fullscreen window.\n";
	std::cout << "\t-res=x,y  --resolution=x,y\t  Play with the resolution x * y.\n";
	std::cout << "\t\t  --desktop-mode\t  Play with the desktop resolution.\n";
	std::cout << std::endl;
}



const std::string& Settings::GetSettings(const std::string& section, const std::string& name) const
{
	return (*(*mySettings.find(section)).second.find(name)).second;
}


sf::VideoMode Settings::GetVideoMode() const
{
	std::stringstream sstr;
	unsigned int x, y;
	sstr << (*(*mySettings.find("Window")).second.find("Width")).second;
	sstr >> x; sstr.clear();
	sstr << (*(*mySettings.find("Window")).second.find("Height")).second;
	sstr >> y;
	return sf::VideoMode(x, y);
}


unsigned long Settings::GetWindowStyle() const
{
	std::stringstream sstr;
	unsigned long style;
	sstr << (*(*mySettings.find("Window")).second.find("Style")).second;
	sstr >> style;
	return style;
}


