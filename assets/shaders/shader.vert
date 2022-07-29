#version 330 core
layout(location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>
layout(location = 1) in vec3 aColor;

out vec3 ourColor;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    ourColor = aColor;
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}