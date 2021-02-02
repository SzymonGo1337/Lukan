#include "Keyboard.hpp"

namespace Lk {
    Keyboard::Keyboard() { }

    vbool Keyboard::CheckKey(LkNativeWindow window, vint key) {
        if(glfwGetKey(window, key) == GLFW_PRESS) {
            return true;
        } else {
            return false;
        }
    }
};