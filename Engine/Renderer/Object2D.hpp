#pragma once
#ifndef LUKAN_OBJECT2D
#define LUKAN_OBJECT2D

#include "../Engine.hpp"

#include "Renderer2D.hpp"

namespace Lk {
    class Object2D {
    public:
        Object2D(vfloat x = 0.20f, vfloat y = 0.20f, vfloat width = 0.10f, vfloat height = 0.10f, vbool inScale = true);

        void BindVAO();
        void BindVBO();
        void BindEBO();

        void UnbindVAO();
        void UnbindVBO();
        void UnbindEBO();

        void Render();

    private:
        vfloat m_x, m_y, m_width, m_height;
        vuint m_VBO, m_VAO, m_EBO;

    };
};

#endif