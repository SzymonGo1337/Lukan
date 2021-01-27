#include "Camera2D.hpp"

namespace Lk {
    Camera2D::Camera2D() {
        m_view = glm::mat4x4(1);
        m_projection = glm::ortho(-1.0f * 16.0f / 9.0f * 0.5f, 1.0f * 16.0f / 9.0f * 0.5f, -1.0f * 0.5f, 1.0f * 0.5f, -1.0f, 1.0f);
    }

    Camera2D::Camera2D(float orthoSize, float aspectRatio, float near, float far) {
        m_view = glm::mat4x4(1);
        m_projection = glm::ortho(-orthoSize * aspectRatio * 0.5f, orthoSize * aspectRatio * 0.5f, -orthoSize * 0.5f, orthoSize * 0.5f, near, far);
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