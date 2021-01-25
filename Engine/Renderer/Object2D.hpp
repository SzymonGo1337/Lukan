#pragma once
#ifndef LUKAN_OBJECT2D
#define LUKAN_OBJECT2D

#include "../Engine.hpp"

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

        void SetPosition(vfloat x, vfloat y, vbool inScale);
        void SetSize(vfloat width, vfloat height, vbool inScale);
        void SetTexture(Texture2D texture);

    private:
        Texture2D m_texture;
        vfloat m_x, m_y, m_width, m_height;
        vuint m_VBO, m_VAO, m_EBO;

    };
};

#endif