#include "Camera2D.hpp"

namespace Lk {
    Camera2D::Camera2D() {
        m_view = glm::mat4x4(1);
        m_projection = glm::ortho(0.0f, (Lk::vfloat)1280.0f, (Lk::vfloat)720.0f, 0.0f, 0.1f, 100.0f);
    }
    
    Camera2D::Camera2D(vfloat fovy, vfloat aspect, vfloat near, vfloat far) {
        m_view = glm::mat4x4(1);
        m_projection = glm::ortho(0.0f, (Lk::vfloat)1280.0f, (Lk::vfloat)720.0f, 0.0f, near, far);
    }

    void Camera2D::Show(vuint u_viewProj) {
        glm::mat4x4 viewProjection = m_projection * glm::inverse(m_view);
        glUniformMatrix4fv(u_viewProj, 1, GL_FALSE, glm::value_ptr(viewProjection));
    }

    void Camera2D::SetViewPosition(vfloat x, vfloat y, vfloat z) {
        m_view[3].x = x;
        m_view[3].y = y;
        m_view[3].z = z;
    }

    glm::mat4x4& Camera2D::GetView() {
        return (glm::mat4x4&)m_view;
    }
};