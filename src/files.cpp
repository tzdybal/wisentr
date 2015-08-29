#include <files.h>

#include <stack>
#include <regex>
#include <boost/filesystem.hpp>


std::vector<std::string> zubr::files::find_all_files(const std::string& directory, const std::string& filter)
{
	using namespace boost::filesystem;
	std::vector<std::string> files;
	std::stack<path> paths;

	paths.push(directory);

	while (!paths.empty()) {
		path p = paths.top(); paths.pop();

		if (exists(p)) {
			if (is_directory(p)) {
				for (directory_entry& e : directory_iterator(p)) {
					paths.push(e.path());
				}
			}
			else if (is_regular_file(p)) {
				files.push_back(p.native());
			}
		}
	}

	return files;	
}
