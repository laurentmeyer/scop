#version 400

in vec4 normal;
in vec3 half;
in vec3 lightdir;
layout(location = 0) out vec4 fragmentColor;
struct LightData {
  vec3 position;
  vec3 intensity;
};
uniform LightData light;
uniform vec3 Ia;
uniform vec3 ka, kd, ks;
uniform float phongExp;
void main(void) {
  vec3 n = normalize(normal.xyz);
  vec3 h = normalize(half);
  vec3 l = normalize(lightdir);
  vec3 intensity = ka * Ia + kd * light.intensity * max(0.0, dot(n, l)) +
                   ks * light.intensity * pow(max(0.0, dot(n, h)), phongExp);
  fragmentColor = vec4(intensity, 1.0);
}