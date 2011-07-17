#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <boost/filesystem.hpp>
#include <string>
#include <list>


class FileSystem
{
	public:
		static std::string GetUserProfileDirectory();
		static std::string GetGameSettingsDirectory();
		
		static std::list<boost::filesystem::path> GetDirectoryContent(const boost::filesystem::path& directory);
};


#endif // FILESYSTEM_HPP


