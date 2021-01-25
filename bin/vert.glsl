#version 330 core
layout (location = 0) in vec3 a_Pos;
layout (location = 2) in vec2 a_TexCoord;
    
out vec2 v_TexCoord;

uniform mat4 u_viewProjection = mat4(1.0);
uniform mat4 u_transform = mat4(1.0);

void main()
{
    v_TexCoord = a_TexCoord;
    gl_Position =  u_viewProjection * u_transform * vec4(a_Pos, 1.0);
}