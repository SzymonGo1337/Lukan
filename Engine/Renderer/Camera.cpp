#include "Camera.hpp"

namespace Lk {
    Camera::Camera() {
        m_view = glm::mat4x4(1);
        m_projection = glm::perspective(glm::radians(90.0f), (Lk::vfloat)1280.0f / (Lk::vfloat)720.0f, 0.001f, 1000.0f);
    }
    
    Camera::Camera(vfloat fovy, vfloat aspect, vfloat near, vfloat far) {
        m_view = glm::mat4x4(1);
        m_projection = glm::perspective(fovy, aspect, near, far);
    }

    void Camera::Show(vuint u_viewProj) {
        glm::mat4x4 viewProjection = m_projection * glm::inverse(m_view);
        glUniformMatrix4fv(u_viewProj, 1, GL_FALSE, glm::value_ptr(viewProjection));
    }

    void Camera::SetViewPosition(vfloat x, vfloat y, vfloat z) {
        m_view[3].x = x;
        m_view[3].y = y;
        m_view[3].z = z;
    }

    glm::mat4x4& Camera::GetView() {
        return (glm::mat4x4&)m_view;
    }
};