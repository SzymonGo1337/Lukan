#include "../Engine/Engine.hpp"

void GLAPIENTRY OpenGLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}

Lk::vfloat x = 0.0f, y = 0.0f;
void Input(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        x = x + 4.0f;
    } else if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        x = x - 4.0f;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        y = y + 4.0f;
    } else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        y = y - 4.0f;
    }
}

#define FPS_LIMIT 60

int main(int argc, char** argv) {
    Lk::LukanGL lukanGLContext(4, 6);

    Lk::Window window("Lukan - Demo");

    lukanGLContext.SetProcessAddress((Lk::vLukanGLLoader)glfwGetProcAddress);
    glViewport(0, 0, 1280, 720);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(OpenGLMessageCallback, NULL);

    Lk::Shader shader("vert.glsl", "frag.glsl", true);

    Lk::Texture2D tex1("res/Lukan.png");

    Lk::Object2D obj1(200.0f, 200.0f, 200.0f, 200.0f, false);
    obj1.SetTexture(tex1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    double lastTime = glfwGetTime();

    while(!LkWindowShouldClose(window.GetNativeWindow())) {
        Input(window.GetNativeWindow());
        window.Clear();

        shader.Bind();

        obj1.SetPosition(x, y, false);
        obj1.Render();

        window.Display();

        while(glfwGetTime() < lastTime + 1.0f / FPS_LIMIT) {

        }
        lastTime += 1.0f / FPS_LIMIT;
    }
}