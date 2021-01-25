#include "Window.hpp"

namespace Lk {
    Window::Window(const vstring& title, vuint width, vuint height, vbool resizable) {
        glfwWindowHint(GLFW_RESIZABLE, resizable);
        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        MakeCurrentContext();
        glfwSwapInterval(0);
    }

    void Window::MakeCurrentContext() {
        glfwMakeContextCurrent(m_window);
    }

    void Window::Clear() {
        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::Display() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Window::Close() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    GLFWwindow* Window::GetNativeWindow() {
        return m_window;
    }
};