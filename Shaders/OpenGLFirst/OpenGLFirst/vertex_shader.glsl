#version 420

in vec3 position;
in vec2 vertTextureCoord;
out vec2 fragTextureCoord;

void main(){
	fragTextureCoord = vertTextureCoord;
	gl_Position = vec4(position, 1.0);
}