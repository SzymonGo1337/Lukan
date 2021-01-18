#pragma once
#ifndef LUKAN_GL
#define LUKAN_GL

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Math.hpp"

namespace Lk {
    using vLukanGLLoader = GLADloadproc;

    class LukanGL {
    public:
        LukanGL(vint major = 3, vint minor = 3);

        void SetProcessAddress(vLukanGLLoader process);

        vint GetMajorVersion();
        vint GetMinorVersion();
        vLukanGLLoader GetProcessAddress();

    private:
        vint m_major, m_minor;
        vLukanGLLoader m_process;
    };
};

#endif