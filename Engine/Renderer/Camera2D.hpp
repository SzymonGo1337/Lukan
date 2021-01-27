#pragma once
#ifndef LUKAN_CAMERA2D
#define LUKAN_CAMERA2D

#include "../Engine.hpp"

namespace Lk {
    class Camera2D {
    public:
        Camera2D();
        Camera2D(float orthoSize, float aspectRatio, float near, float far);

        void Show(vuint u_viewProj);

        void SetViewPosition(vfloat x, vfloat y, vfloat z);

        glm::mat4x4& GetView();

    private:
        glm::mat4x4 m_view;
        glm::mat4x4 m_projection;
    };
};

#endif