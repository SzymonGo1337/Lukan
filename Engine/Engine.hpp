#pragma once
#ifndef LUKAN_ENGINE
#define LUKAN_ENGINE

#ifdef _WIN32
	#define LUKAN_WINDOWS
	#define LUKAN_OS "WINDOWS"
#elif defined(__linux__)
	#define LUKAN_LINUX
	#define LUKAN_OS "LINUX"
#else
	#error "Not supported platform!"
#endif

#include <vector>
#include <array>
#include <unordered_map>
#include <map>

#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <chrono>
#include <filesystem>
#include <sstream>
#include <string>

#include "LukanGL.hpp"

#include "Window.hpp"

#endif