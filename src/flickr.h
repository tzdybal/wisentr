#pragma once

#include <string>

namespace zubr {
namespace flickr {

struct config {
	std::string client_key;
	std::string client_secret;
	std::string token;
	std::string token_secret;
};

class flickr {
public:
	flickr();
	flickr(const flickr&) = delete;
	virtual ~flickr();
	void upload(const std::string& file);
private:
};

} // namespace flickr
} // namespace zubr
