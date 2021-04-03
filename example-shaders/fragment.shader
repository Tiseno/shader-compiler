#version 300 es

precision mediump float;

uniform float avar;

out vec4 fragmentColor;

void main() {
  f ragmentColor = vec4 (gl_TexCoord.x, 0.0, 0.0, 1.0);
}

