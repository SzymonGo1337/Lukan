#include "Texture2D.hpp"

namespace Lk {
    Texture2D::Texture2D() {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.1);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glColor4f(1, 1, 1, 1);
    }

    Texture2D::Texture2D(const vchar* filename) {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.1);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glColor4f(1, 1, 1, 1);

        m_texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    }

    void Texture2D::Bind() {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    void Texture2D::Unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    vbool Texture2D::HasValue() {
        if(m_texture > 0) {
            return true;
        } else {
            return false;
        }
    }
};