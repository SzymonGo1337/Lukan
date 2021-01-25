#pragma once
#ifndef LUKAN_CAMERA
#define LUKAN_CAMERA

#include "../Engine.hpp"

namespace Lk {
    class Camera {
    public:
        Camera();
        Camera(vfloat fovy, vfloat aspect, vfloat near, vfloat far);

        void Show(vuint u_viewProj);

        void SetViewPosition(vfloat x, vfloat y, vfloat z);

        glm::mat4x4& GetView();

    private:
        glm::mat4x4 m_view;
        glm::mat4x4 m_projection;
    };
};

#endif