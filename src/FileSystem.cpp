#include "FileSystem.hpp"

#include <cstdlib>
#include <iostream>


namespace bfs = boost::filesystem;


bfs::path FileSystem::GetUserProfileDirectory()
{
	#if defined linux || defined __linux
		return bfs::path(std::getenv("HOME"));
	#elif defined _WIN32 || defined __WIN32__
		return bfs::path(std::getenv("APPDATA"));
	#else
		#warning "No userprofile directory found. Using './MedievalWar' for configuration files."
		return bfs::path("./");
	#endif
}


bfs::path FileSystem::GetGameSettingsDirectory()
{
	bfs::path directory(GetUserProfileDirectory());
	
	if(directory.string()[directory.string().size() - 1] != '/')
	{
		directory /= "/";
	}
	
	#if defined linux || defined __linux
		directory /= ".medieval-war/";
	#elif defined _WIN32 || defined __WIN32__
		directory /= "MedievalWar/";
	#else
		directory /= "MedievalWar/";
	#endif
	
	return directory;
}


std::list<bfs::path> FileSystem::GetDirectoryContent(const bfs::path& directory)
{
	try
	{
		if(bfs::exists(directory) && bfs::is_directory(directory))
		{
			std::list<bfs::path> content;
		
			copy(bfs::directory_iterator(directory), bfs::directory_iterator(), std::back_inserter(content));
			content.sort();
			
			return content;
		}
		else
		{
			std::cerr << "Failed to read the content of " << directory << ": Not a directory.\n";
		}
	
	}
	catch(const bfs::filesystem_error& ex)
	{
		std::cerr << "Error while reading the content of a directory:\n" << ex.what() << "\n\n";
	}
	
	return std::list<bfs::path>();
}


