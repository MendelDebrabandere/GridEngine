#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Singleton.h"

namespace grid
{
	class Texture;
	class Mesh;
	class Effect;

	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		void Init(const std::string& data);

		void CheckForDeletedTextures();

		std::shared_ptr<Texture> LoadTexture(const std::string& file, ID3D11Device* pDevice);
		std::shared_ptr<Mesh> LoadMesh(ID3D11Device* pDevice, const std::string& objectPath, Effect* pEffect);
	private:
		friend class Singleton<ResourceManager>;
		ResourceManager() = default;
		std::string m_dataPath;

		std::unordered_map<std::string, std::shared_ptr<Texture>> m_Textures{};
		std::unordered_map<std::string, std::shared_ptr<Mesh>> m_Meshes{};
	};
}
