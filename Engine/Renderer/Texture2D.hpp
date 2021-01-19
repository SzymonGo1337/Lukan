#pragma once
#ifndef LUKAN_TEXTURE2D
#define LUKAN_TEXTURE2D

#include "../LukanGL.hpp"

#include <SOIL2/SOIL2.h>

namespace Lk {
    class Texture2D {
    public:
        Texture2D(const vchar* filename);

        void Bind();
        void Unbind();

    private:
        vuint m_texture;

    };
};

#endif