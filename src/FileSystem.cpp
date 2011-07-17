#include "FileSystem.hpp"

#include <cstdlib>


namespace bfs = boost::filesystem;


std::string FileSystem::GetUserProfileDirectory()
{
	#if defined linux || defined __linux
		return std::getenv("HOME");
	#elif defined _WIN32 || defined __WIN32__
		return std::getenv("APPDATA");
	#else
		#warning "No userprofile directory found. Using './MedievalWar' for configuration files."
		return "./";
	#endif
}


std::string FileSystem::GetGameSettingsDirectory()
{
	std::string directory(GetUserProfileDirectory());
	
	if(directory[directory.size() - 1] != '/')
	{
		directory += "/";
	}
	
	#if defined linux || defined __linux
		directory += ".medieval-war/";
	#elif defined _WIN32 || defined __WIN32__
		directory += "MedievalWar/";
	#else
		directory += "MedievalWar/";
	#endif
	
	return directory;
}


std::list<bfs::path> FileSystem::GetDirectoryContent(const bfs::path& directory)
{
	bfs::path p(directory);
	
	try
	{
		if(bfs::exists(p) && bfs::is_directory(p))
		{
			std::list<bfs::path> content;
		
			copy(bfs::directory_iterator(p), bfs::directory_iterator(), std::back_inserter(content));
			content.sort();
			
			return content;
		}
		else
		{
			std::cerr << "Failed to read the content of " << p << ": Not a directory.\n";
			return std::list<bfs::path>();
		}
	
	}
	catch (const bfs::filesystem_error& ex)
	{
		std::cerr << ex.what() << '\n';
	}
}


