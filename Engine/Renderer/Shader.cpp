#include "Shader.hpp"

namespace Lk {
    Shader::Shader(const vchar* vertexShaderSource, const vchar* fragmentShaderSource) {
        vuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        vuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        m_program = glCreateProgram();
        glAttachShader(m_program, vertexShader);
        glAttachShader(m_program, fragmentShader);
        glLinkProgram(m_program);
    }
    
    Shader::Shader(std::string vertexShaderFilename, std::string fragmentShaderFilename, vbool loadFromFile) {
        std::string  content1, content2;
        std::ifstream vertexFile(vertexShaderFilename, std::ios::in);
        std::ifstream fragmentFile(fragmentShaderFilename, std::ios::in);

        std::string  line1 = "";
        while(!vertexFile.eof()) {
            std::getline(vertexFile, line1);
            content1.append(line1 + "\n");
        }

        vertexFile.close();
        const vchar* vertexShaderSource = content1.c_str();

        std::string line2 = "";
        while(!fragmentFile.eof()) {
            std::getline(fragmentFile, line2);
            content2.append(line2 + "\n");
        }

        fragmentFile.close();
        const vchar* fragmentShaderSource = content2.c_str();

        vuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        vuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        m_program = glCreateProgram();
        glAttachShader(m_program, vertexShader);
        glAttachShader(m_program, fragmentShader);
        glLinkProgram(m_program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::Bind() {
        glUseProgram(m_program);
    }
    
    void Shader::Unbind() {
        glUseProgram(0);
    }

    vuint Shader::GetUniformLocation(vchar* uniform) {
        return glGetUniformLocation(GetProgram(), uniform);
    }
    
    vuint Shader::GetProgram() {
        return m_program;
    }
};