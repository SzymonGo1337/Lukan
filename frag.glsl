#version 330 core
uniform vec4 u_Color = vec4(1.0, 1.0, 1.0, 1.0);
uniform sampler2D u_Texture;
                
out vec4 Color;
in vec2 v_TexCoord;

void main()
{
    Color = u_Color * texture2D(u_Texture, v_TexCoord); // vec4(v_TexCoord, 0, 1);
}