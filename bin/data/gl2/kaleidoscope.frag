#version 120

const float PI = 3.141592658;
const float TAU = 2.0 * PI;
const float sections = 10.0;

uniform vec2 resolution;
uniform float time;
uniform vec2 mouse;

uniform sampler2DRect tex0;
varying vec2 texCoordVarying;

void main(void){
   vec2 pos = // vec2(
   gl_FragCoord.xy;// - resolution*0.5;//*resolution - 0.5 * resolution) / resolution.y;

  float rad = length(pos);
  float angle = atan(pos.y, pos.x);

  float ma = mod(angle, TAU/sections);
  ma = abs(ma - PI/sections);
  
  float x = cos(ma) * rad;
  float y = sin(ma) * rad;
	
  float t = time/10.;
  
  gl_FragColor = texture2DRect(tex0, pos);//vec2(x-t, y-t)); //vec4(pos.x,pos.y,0,1.0) * 
  
}

/*float Tile1D(float p, float a){
  p -= 4.0 * a * floor(p/4.0 * a);
  p -= 2.* max(p - 2.0 * a , 0.0);
  return p;
}*/