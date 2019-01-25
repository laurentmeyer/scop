#version 400

in vec3 in_Position;
in vec2 in_TexCoord;
out vec2 tCoord;
uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
void main(void) {
  tCoord = in_TexCoord;
  gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
}