#include "Texture2D.hpp"

namespace Lk {
    Texture2D::Texture2D(const vchar* filename) {
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_set_flip_vertically_on_load(true);
        m_data = stbi_load(filename, &m_width, &m_height, &m_nrChannels, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(m_data);
    }

    void Texture2D::Bind() {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    void Texture2D::Unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};