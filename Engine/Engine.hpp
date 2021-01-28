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

#define WIDTH 1280
#define HEIGHT 720

#include "Systems/Files.hpp"
#include "Systems/Error.hpp"

#include "LukanGL.hpp"

#include "Window.hpp"

#include "Renderer/Shader.hpp"
#include "Renderer/Texture2D.hpp"
#include "Renderer/Object2D.hpp"
#include "Renderer/Camera2D.hpp"
#include "Renderer/Camera.hpp"

// #include "GUI/GUI.hpp"

#endif