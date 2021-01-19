#include "Texture2D.hpp"

namespace Lk {
    Texture2D::Texture2D(const vchar* filename) {
        m_texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    }

    void Texture2D::Bind() {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    void Texture2D::Unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};