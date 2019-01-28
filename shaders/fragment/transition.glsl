#version 400

in vec2 triangleCoord;
in vec2 sphereCoord;
in vec3 pos;
out vec4 frag_colour;
uniform sampler2D textureUnit;
uniform float textureSlider;
uniform float uvSlider;
void main() {
  float f = (1.0 - textureSlider) * ( 1 + gl_PrimitiveID % 4) / 5.;
  vec4 triangleUv = (1.0 - uvSlider) * texture(textureUnit, triangleCoord);
  vec4 sphereUv = uvSlider * texture(textureUnit, sphereCoord);
  frag_colour = textureSlider * (triangleUv + sphereUv) + vec4(f, f, f, 1.0);
}