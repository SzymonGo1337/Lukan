#pragma once
#ifndef LUKAN_WINDOW
#define LUKAN_WINDOW

#include "Engine.hpp"

#include <GLFW/glfw3.h>

#define LkWindowShouldClose glfwWindowShouldClose

namespace Lk {
    class Window {
    public:
        Window(const vstring& title = "Lukan - Engine", vuint width = WIDTH, vuint height = HEIGHT, vbool resizable = false);

        void MakeCurrentContext();
        void Clear();
        void Display();
        void Close();
        
        GLFWwindow* GetNativeWindow();

    private:
        GLFWwindow* m_window;
    };
};

#endif