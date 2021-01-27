#include "../Engine/Engine.hpp"

Lk::Camera2D camera;

// TODO: keyboard class
void Input(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.GetView()[3].x -= 0.0005f;
    } else if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.GetView()[3].x += 0.0005f;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.GetView()[3].z -= 0.0005f;
    } else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.GetView()[3].z += 0.0005f;
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        camera.GetView()[3].x -= 0.0005f;
    } else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        camera.GetView()[3].x += 0.0005f;
    }

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        camera.GetView()[3].y += 0.0005f;
    } else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        camera.GetView()[3].y -= 0.0005f;
    }
}

int main(int argc, char** argv) {
    Lk::LukanGL lukanGLContext(4, 6);

    Lk::Window window("Lukan - Demo");

    lukanGLContext.SetProcessAddress((Lk::vLukanGLLoader)glfwGetProcAddress);
    glViewport(0, 0, 1280, 720);

    Lk::ErrorHandler errorHandler;

    Lk::Shader shader("vert.glsl", "frag.glsl", true);
    
    Lk::Object2D obj1; //(200.0f, 200.0f, 200.0f, 200.0f, false);
    obj1.SetPosition(0.0f, 0.0f, 0.0f, false);
    obj1.LoadTexture("res/Lukan.png");

    Lk::vuint u_viewProjection = shader.GetUniformLocation("u_viewProjection");
    Lk::vuint u_transform = shader.GetUniformLocation("u_transform");

    //camera.SetViewPosition(-0.25f, 0.5f, 1.0f);
    //std::cout << camera.GetView()[3].x << " | " << camera.GetView()[3].y << " | " << camera.GetView()[3].z << "\n";

    while(!LkWindowShouldClose(window.GetNativeWindow())) {
        Input(window.GetNativeWindow());
        window.Clear();

        shader.Bind();

        camera.Show(u_viewProjection);

        //obj1.SetPosition(x, y, false);
        obj1.Render();

        window.Display();
    }
}