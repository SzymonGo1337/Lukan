#include "LukanGL.hpp"

namespace Lk {
    LukanGL::LukanGL(vint major, vint minor) {
        m_major = major;
        m_minor = minor;

        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void LukanGL::SetProcessAddress(vLukanGLLoader process) {
        m_process = process;

        gladLoadGLLoader(process);
    }

    vint LukanGL::GetMajorVersion() {
        return m_major;
    }
    
    vint LukanGL::GetMinorVersion() {
        return m_minor;
    }
    
    vLukanGLLoader LukanGL::GetProcessAddress() {
        return m_process;
    }
};