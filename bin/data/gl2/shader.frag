#version 120

// this is how we receive the texture
uniform sampler2DRect tex0;

varying vec2 texCoordVarying;

void main()
{
   gl_FragColor = texture2DRect(tex0, vec2(gl_FragCoord.x, -gl_FragCoord.y));//texCoordVarying);
   
   /*float windowWidth = 1024.0;
   float windowHeight = 768.0;
   
   float r = gl_FragCoord.x / windowWidth;
   float g = gl_FragCoord.y / windowHeight;
   float b = 1.0;
   float a = 1.0;
   gl_FragColor = vec4(r, g, b, a);*/
}