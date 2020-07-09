#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec4 aTexCoord;

out vec4 vertexColor;
out vec2 texCoord;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vertexColor = aColor;
	texCoord = vec2(aTexCoord.x, aTexCoord.y);
}