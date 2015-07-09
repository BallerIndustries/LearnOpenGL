#version 330 core
in vec3 ourColor;
in vec2 ourTextureCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{	
    color = mix(texture(ourTexture1, ourTextureCoord), texture(ourTexture2, ourTextureCoord), 0.2);
}