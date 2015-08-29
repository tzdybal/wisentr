#include <iostream>
#include <string>

#include <ui.h>
#include <log.h>

int main(int argc, char** argv)
{
	using namespace zubr::log;
	using namespace zubr::ui;

	std::string directory = ".";

	if (argc >= 2) {
		directory = argv[1];
	}

	logger log;
	log.set_log_level(level::INFO);

	log(level::DEBUG, "Starting application in directory: ", directory);



	log(level::DEBUG, "Exiting application");
}
