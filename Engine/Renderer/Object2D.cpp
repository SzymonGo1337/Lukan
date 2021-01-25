#include "Object2D.hpp"

namespace Lk {
    Object2D::Object2D(vfloat x, vfloat y, vfloat width, vfloat height, vbool inScale) {
        if(inScale) {
            m_x = x;
            m_y = y;
            m_width = width;
            m_height = height;
        } else {
            m_x = -(x / (WIDTH / 2));
            m_y = y / (HEIGHT / 2);
            m_width = width / WIDTH;
            m_height = height / HEIGHT;
        }

        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(1, &m_VBO);
        glGenBuffers(1, &m_EBO);

        BindVAO();
        BindVBO();
        BindEBO();

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    void Object2D::BindVAO() {
        glBindVertexArray(m_VAO);
    }
    
    void Object2D::BindVBO() {
        vfloat vertices[] = {
            // positions                             // colors          // texture
            m_x +  m_width, m_y +  m_height, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
            m_x +  m_width, m_y + -m_height, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
            m_x + -m_width, m_y + -m_height, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
            m_x + -m_width, m_y +  m_height, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f
        };

        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }
    
    void Object2D::BindEBO() {
        vuint indices[] = {  
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }

    void Object2D::UnbindVAO() {
        glBindVertexArray(0);
    }
        
    void Object2D::UnbindVBO() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    void Object2D::UnbindEBO() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void Object2D::Render() {
        if(m_texture.HasValue()) {
            m_texture.Bind();
        }

        BindVAO();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        UnbindVAO();
    }

    void Object2D::SetPosition(vfloat x, vfloat y, vbool inScale) {
        if(inScale) {
            m_x = x;
            m_y = y;
        } else {
            m_x = -(x / (WIDTH / 2));
            m_y = y / (HEIGHT / 2);
        }
        BindVBO();
        BindEBO();
    }
    
    void Object2D::SetSize(vfloat width, vfloat height, vbool inScale) {
        if(inScale) {
            m_width = width;
            m_height = height;
        } else {
            m_width = width / WIDTH;
            m_height = height / HEIGHT;
        }
        BindVBO();
        BindEBO();
    }

    void Object2D::SetTexture(Texture2D texture) {
        m_texture = texture;
    }
};