#version 400

in vec3 in_Position;
in vec2 in_TexCoordTriangle;
in vec2 in_TexCoordSphere;
out vec2 triangleCoord;
out vec2 sphereCoord;
out vec3 pos;
uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
void main(void) {
  triangleCoord = in_TexCoordTriangle;
  sphereCoord = in_TexCoordSphere;
  pos = in_Position;
  gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
}