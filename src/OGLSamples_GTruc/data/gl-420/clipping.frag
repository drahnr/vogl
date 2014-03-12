#version 420 core

#define POSITION	0
#define COLOR		3
#define TEXCOORD	4
#define FRAG_COLOR	0

layout(binding = 0) uniform sampler2D Diffuse;

in block
{
	vec4 Position;
	vec2 Texcoord;
} In;

layout(location = FRAG_COLOR, index = 0) out vec4 Color;

void main()
{
	if(In.Position.z > 16)
		discard;

	Color = texture(Diffuse, In.Texcoord.st);
}
