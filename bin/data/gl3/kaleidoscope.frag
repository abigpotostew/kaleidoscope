#version 150

const float PI = 3.141592658;
const float TAU = 2.0 * PI;
const float sections = 10.0;

uniform vec2 resolution;
uniform float time;
uniform sampler2DRect tex0;

in vec2 varyingtexcoord;

out vec4 outputColor;

void main(void){
   vec2 pos = (gl_FragCoord.xy - resolution*0.5);//vec2(varyingtexcoord - 0.5 * resolution) / resolution.y;

  float rad = length(pos);
  float angle = atan(pos.y, pos.x);

  float ma = mod(angle, TAU/sections);
  ma = abs(ma - PI/sections);
  
  float x = cos(ma) * rad;
  float y = sin(ma) * rad;
	
  float t = time*5.0;
  
   outputColor = texture(tex0, vec2(x-t, y-t));
}
