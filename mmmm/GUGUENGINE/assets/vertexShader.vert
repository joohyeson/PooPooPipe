#version 400
in vec3 vp;

uniform mat3 to_ndc;

void main()
{
	vec3 p = to_ndc * vp;
    gl_Position = vec4(p, 1.0);
}