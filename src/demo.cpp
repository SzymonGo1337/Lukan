#include "../Engine/Engine.hpp"

const char* vertSrc = R"(
    #version 460 core
    layout (location = 0) in vec3 a_Pos;
    layout (location = 1) in vec2 a_TexCoord;
    out vec2 v_TexCoord;
    uniform mat4 u_viewProjection = mat4(1.0);
    uniform mat4 u_transform = mat4(1.0);
    void main()
    {
        v_TexCoord = a_TexCoord;
        gl_Position =  u_viewProjection * u_transform * vec4(a_Pos, 1.0);
    }	
)";

const char* fragSrc = R"(
    #version 460 core
    uniform vec4 u_Color = vec4(1.0, 1.0, 1.0, 1.0);
    uniform sampler2D u_Texture;
                
    out vec4 Color;
    in vec2 v_TexCoord;
    void main()
    {
        Color = u_Color * texture(u_Texture, v_TexCoord); // vec4(v_TexCoord, 0, 1);
    }
)";

int main(int argc, char** argv) {
    Lk::LukanGL lukanGLContext(4, 6);

    Lk::Window window("Lukan - Demo");

    lukanGLContext.SetProcessAddress((Lk::vLukanGLLoader)glfwGetProcAddress);
    glViewport(0, 0, 1280, 720);

    Lk::Shader shader(vertSrc, fragSrc);

    Lk::Object2D obj1(200.0f, 200.0f, 200.0f, 200.0f, false);

    Lk::Texture2D tex1("res/Lukan.png");

    while(!glfwWindowShouldClose(window.GetNativeWindow())) {
        window.Clear();

        tex1.Bind();
        shader.Bind();
        obj1.Render();

        window.Display();
    }
}