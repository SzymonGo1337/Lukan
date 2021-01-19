#pragma once
#ifndef LUKAN_TEXTURE2D
#define LUKAN_TEXTURE2D

#include "../LukanGL.hpp"

#include <SOIL2/stb_image.h>

namespace Lk {
    class Texture2D {
    public:
        Texture2D(const vchar* filename);

        void Bind();
        void Unbind();

    private:
        vuint m_texture;
        vint m_width, m_height, m_nrChannels;
        unsigned char *m_data;

    };
};

#endif