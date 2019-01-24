#version 400

in vec3 in_Position;
in vec3 in_Color;
out vec3 vColor;
uniform mat4 projMatrix;
void main() {
  // vColor = in_Color;
  vColor = vec3(1.0, 1.0, 0.0);
  gl_Position = projMatrix * vec4(in_Position, 1.0);
}