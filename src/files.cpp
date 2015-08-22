#include <files.h>

#include <stack>
#include <boost/filesystem.hpp>


std::vector<std::string> zubr::files::find_all_images(const std::string& directory, const std::string& filter)
{
	using namespace boost::filesystem;
	std::vector<std::string> images;
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
				images.push_back(p.native());
			}
		}
	}

	return images;	
}
