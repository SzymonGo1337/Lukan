#pragma once
#ifndef LUKAN_SHADER
#define LUKAN_SHADER

#include <fstream>

#include "../LukanGL.hpp"

namespace Lk {
    class Shader {
    public:
        Shader(const vchar* vertexShaderSource, const vchar* fragmentShaderSource);
        Shader(std::string vertexShaderFilename, std::string fragmentShaderFilename, vbool loadFromFile);

        void Bind();
        void Unbind();

        vuint GetUniformLocation(vchar* uniform);
        vint GetAttribLocation(vchar* attrib);
        vuint GetProgram();

    private:
        vuint m_program;

    };
};

#endif