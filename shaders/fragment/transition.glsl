#version 400

in vec2 tCoord;
in vec3 pos;
out vec4 frag_colour;
uniform sampler2D textureUnit;
uniform float textureSlider;
void main() {
  float f = (1.0 - textureSlider) * ( 1 + gl_PrimitiveID % 4) / 5.;
  frag_colour = textureSlider * texture(textureUnit, tCoord) + vec4(f, f, f, 1.0);
}