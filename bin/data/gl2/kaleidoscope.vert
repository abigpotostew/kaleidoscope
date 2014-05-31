#version 120

// this is something we're creating for this shader
varying vec2 texCoordVarying;

// this is coming from our C++ code
uniform vec2 mouse;

void main()
{
   gl_TexCoord[0] = gl_MultiTexCoord0;
	vec2 texcoord = vec2(gl_MultiTexCoord0.x , gl_MultiTexCoord0.y );
	
   vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;

   // here we move the texture coordinates
   texCoordVarying = vec2(texcoord.x - mouse.x, texcoord.y - mouse.y);

    // send the vertices to the fragment shader
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}