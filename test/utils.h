#pragma once

#include <string>
#include <boost/filesystem.hpp>

namespace utils {

class scoped_directory {
public:
	scoped_directory(const boost::filesystem::path& string);
	~scoped_directory();
	boost::filesystem::path path();
private:
	boost::filesystem::path path_;
};

} // namespace utils
