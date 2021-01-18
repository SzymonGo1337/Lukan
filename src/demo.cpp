#include "../Engine/Engine.hpp"

int main(int argc, char** argv) {
    Lk::LukanGL lukanGLContext(4, 6);

    Lk::Window window("Lukan - Demo");

    lukanGLContext.SetProcessAddress((Lk::vLukanGLLoader)glfwGetProcAddress);
    glViewport(0, 0, 1280, 720);

    while(!glfwWindowShouldClose(window.GetNativeWindow())) {
        window.Clear();

        

        window.Display();
    }
}