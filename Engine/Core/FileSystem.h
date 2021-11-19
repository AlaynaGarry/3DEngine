#pragma once
#include <SDL.h>
#include <string>

namespace nc {
	void SetFilePath(const std::string& pathname);
	std::string GetFilePath();
	bool ReadFileToString(const std::string& filename, std::string& filestring);

}