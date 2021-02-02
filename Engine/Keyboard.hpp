#pragma once
#ifndef LUKAN_KEYBOARD
#define LUKAN_KEYBOARD

#include "Engine.hpp"

#define LkNativeWindow GLFWwindow*

namespace Lk {
    class Keyboard {
    public:
        Keyboard();

        vbool CheckKey(LkNativeWindow window, vint key);

    };
};

#endif