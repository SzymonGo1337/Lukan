#pragma once
#ifndef LUKAN_ERRORHANDLER
#define LUKAN_ERRORHANDLER

#include "../Engine.hpp"
#include "../LukanGL.hpp"
#include "../Math.hpp"

namespace Lk {
    class ErrorHandler {
    public:
        ErrorHandler();

        void GLAPIENTRY OpenGLMessageCallback(vuint source, vuint type, vuint id, vuint severity, vint length, const vchar* message, const void* userParam);
        void GLFWMessageCallback(vint error, const vchar* description);
        
    };
};

#endif