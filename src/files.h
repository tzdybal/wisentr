#pragma once

#include <string>
#include <vector>

namespace zubr {
namespace files {

std::vector<std::string> find_all_files(const std::string& directory, const std::string& filter = "");

} // namespace files
} // namespace zubr
