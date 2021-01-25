#include "Error.hpp"

namespace Lk {
    ErrorHandler::ErrorHandler() {
        glfwSetErrorCallback((GLFWerrorfun)&GLFWMessageCallback);

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback((GLDEBUGPROC)&OpenGLMessageCallback, NULL);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_FALSE);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    void GLAPIENTRY ErrorHandler::OpenGLMessageCallback(vuint source, vuint type, vuint id, vuint severity, vint length, const vchar* message, const void* userParam) {
        std::cerr << "OPENGL CALLBACK: TYPE = " << type << ", SEVERITY = " << severity << ", MESSAGE = " << message << "\n";
        //fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
    }
    
    void ErrorHandler::GLFWMessageCallback(vint error, const vchar* description) {
        std::cerr << "GLFW CALLBACK: " << description << "\n";
        //fprintf(stderr, "GLFW CALLBACK: %s\n", description);
    }
};