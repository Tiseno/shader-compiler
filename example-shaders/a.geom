#version 300 es

precision mediump float;

out vec4 fragmentColor;

void main() {
  fragmentColor = vec4 (gl_TexCoord.x, 0.0, 0.0, 1.0);
}

