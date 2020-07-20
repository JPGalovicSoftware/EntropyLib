#pragma once

#include "../Math/Vec3.h"
#include "../Math/Vec2.h"

#include "Shader.h"

#include <string>
#include <vector>

namespace Entropy
{
	namespace Graphics
	{
		struct __declspec(dllexport) FaceIndex
		{
			unsigned int Position;
			unsigned int Normal;
			unsigned int TexCoord;
		};

		struct __declspec(dllexport) Vertex
		{
			Math::Vec3 Position;
			Math::Vec3 Normal;
			Math::Vec2 TexCoord;

			Vertex(Math::Vec3 position, Math::Vec3 normal = Math::Vec3(), Math::Vec2 texCoord = Math::Vec2()) : Position(position), Normal(normal), TexCoord(texCoord) {};
			Vertex(float x, float y, float z, float i = 0.0f, float j = 0.0f, float k = 0.0f, float tX = 0.0f, float tY = 0.0f) : Position(x, y, z), Normal(i, j, k), TexCoord(tX, tY) {};
		};

		struct __declspec(dllexport) Texture
		{
			unsigned int ID;
			const char* Type;

			Texture(unsigned int ID, const char* type) : ID(ID), Type(type) {};
		};

		class __declspec(dllexport) Mesh
		{
		public:
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
			void Draw(Shader& shader);
		private:
			unsigned int VAO, VBO, EBO;
			
			void setupMesh();
		};

		Mesh __declspec(dllexport) LoadWavefrontObj(const char* filename);
		std::vector<Texture> __declspec(dllexport) LoadTextures(const char* filename);
	}
}