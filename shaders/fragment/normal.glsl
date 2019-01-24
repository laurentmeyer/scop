#version 400

in vec4 normal;
layout(location=0) out vec4 fragmentColor;
void main(void)
{
// Notice the use of swizzling here to access
// only the xyz values to convert the normal vec4 // into a vec3 type!
vec3 intensity = normalize(normal.xyz) * 0.5 + 0.5;
fragmentColor = vec4( intensity, 1.0 );
}
