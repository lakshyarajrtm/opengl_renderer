
#version 460 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec4 vColor;

out vec4 fColor;

layout (location = 0) uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(vPosition, 1.0);
	fColor = vColor;
}