#version 400

in vec2 tCoord;
out vec4 frag_colour;
uniform sampler2D textureUnit;
void main() {
  // float f = ( 1 + gl_PrimitiveID % 4) / 5.;
  // frag_colour = vec4(f, f, f, 1.0);
  frag_colour = texture(textureUnit, tCoord);
}