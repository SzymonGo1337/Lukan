#include "../Engine/Engine.hpp"

Lk::Camera camera;

Lk::Keyboard keyboard;

void Input(LkNativeWindow window) {
    if(keyboard.CheckKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }

    if(keyboard.CheckKey(window, GLFW_KEY_A)) {
        camera.GetView()[3].x -= 0.0005f;
    } else if(keyboard.CheckKey(window, GLFW_KEY_D)) {
        camera.GetView()[3].x += 0.0005f;
    }

    if(keyboard.CheckKey(window, GLFW_KEY_W)) {
        camera.GetView()[3].z -= 0.0005f;
    } else if(keyboard.CheckKey(window, GLFW_KEY_S)) {
        camera.GetView()[3].z += 0.0005f;
    }

    if(keyboard.CheckKey(window, GLFW_KEY_LEFT)) {
        camera.GetView()[3].x -= 0.0005f;
    } else if(keyboard.CheckKey(window, GLFW_KEY_RIGHT)) {
        camera.GetView()[3].x += 0.0005f;
    }

    if(keyboard.CheckKey(window, GLFW_KEY_UP)) {
        camera.GetView()[3].y += 0.0005f;
    } else if(keyboard.CheckKey(window, GLFW_KEY_DOWN)) {
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

    /* IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window.GetNativeWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    ImGui::StyleColorsDark(); */

    while(!LkWindowShouldClose(window.GetNativeWindow())) {
        Input(window.GetNativeWindow());
        window.Clear();

        /* ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame(); */

        shader.Bind();

        camera.Show(u_viewProjection);

        //obj1.SetPosition(x, y, false);
        obj1.Render();

        /* ImGui::Begin("Lukan Engine");
        ImGui::Button("Close");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); */

        window.Display();
    }

    /* ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext(); */
}