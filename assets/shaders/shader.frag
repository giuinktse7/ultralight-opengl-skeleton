#version 330 core
in vec2 TexCoords;
out vec4 color;

in vec3 ourColor;
uniform sampler2D image;

void main()
{
    color = texture(image, TexCoords);
}