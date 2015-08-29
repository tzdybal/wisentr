#define BOOST_TEST_MODULE UnitTests
#define BOOST_TEST_DYN_LINK

#include <fstream>
#include <iostream>
#include <iterator>

#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>
#include <files.h>

#include "utils.h"

BOOST_AUTO_TEST_SUITE(files)

BOOST_AUTO_TEST_CASE(recursive_search)
{
	using namespace boost::filesystem;

	utils::scoped_directory test_root(temp_directory_path() / unique_path());

	path f1 = test_root.path() / "file1.txt";
	path f2 = test_root.path() / "file2.txt";

	utils::scoped_directory subdir1(test_root.path() / "directory1");
	path f3 = subdir1.path() / "file3.txt";
	path f4 = subdir1.path() / "file4.txt";

	std::vector<path> files { f1, f2, f3, f4 };

	for (const path& p: files) {
		std::ofstream f(p.native());
		f << "";
	}

	std::vector<std::string> result = zubr::files::find_all_files(test_root.path().native(), "");

	BOOST_REQUIRE_EQUAL(4, result.size());
}

BOOST_AUTO_TEST_SUITE_END()
