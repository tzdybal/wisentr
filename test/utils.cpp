#include "utils.h"

#include <iostream>

namespace utils {

scoped_directory::scoped_directory(const boost::filesystem::path& path) : path_(path)
{
	create_directory(path_);
}

scoped_directory::~scoped_directory()
{
	remove_all(path_);
}

boost::filesystem::path scoped_directory::path()
{
	return path_;
}

}
