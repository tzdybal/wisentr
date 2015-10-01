#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

#include <ui.h>
#include <log.h>
#include <files.h>
#include <flickr.h>

int main(int argc, char** argv)
{
	using namespace zubr::log;
	using namespace zubr::ui;
	using namespace zubr::files;
	using namespace zubr::flickr;

	std::string directory = ".";

	if (argc >= 2) {
		directory = argv[1];
	}

	logger log;
	//	log.set_log_level(level::INFO);

	log(level::DEBUG, "Starting application in directory: ", directory);

	std::vector<std::string> files = find_all_files(directory);
	// TODO: implement proper filtering
	files.erase(std::remove_if(files.begin(), files.end(),
				[](const std::string& str) -> bool {
					size_t p = str.find_last_of(".");
					std::string ext = p != std::string::npos ? str.substr(p) : "";
					return !(ext == ".JPG" || ext == ".jpg" || ext == ".jpeg" || ext == ".JPEG");
	}), files.end());

	log(level::INFO, "Found ", files.size(), " files");

	flickr f;

	for (auto file : files) {
		log(level::INFO, "Uploading ", file);
		f.upload(file);
	}

	log(level::DEBUG, "Exiting application");
}
