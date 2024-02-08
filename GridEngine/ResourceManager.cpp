#include "pch.h"
#include <stdexcept>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"
#include "Mesh.h"

using namespace grid;

void ResourceManager::Init(const std::string& dataPath)
{
	m_dataPath = dataPath;

}

void ResourceManager::CheckForDeletedTextures()
{
	//std::string deleteStr{};
	//for (const auto& pair : m_Textures)
	//{
	//	if (pair.second.use_count() <= 1)
	//	{
	//		deleteStr = pair.first;
	//		break;
	//	}
	//}
	//if (!deleteStr.empty())
	//	m_Textures.erase(deleteStr);
}

std::shared_ptr<Texture> ResourceManager::LoadTexture(const std::string& file, ID3D11Device* pDevice)
{
	if (m_Textures.contains(file))
	{
		return m_Textures[file];
	}

	const auto fullPath = m_dataPath + file;
	std::shared_ptr<Texture> text{ Texture::LoadFromFile(file, pDevice) };
	m_Textures[file] = text;

	return m_Textures[file];
}

std::shared_ptr<Mesh> grid::ResourceManager::LoadMesh(ID3D11Device* pDevice, const std::string& file, Effect* pEffect)
{
	if (m_Meshes.contains(file))
	{
		return m_Meshes[file];
	}

	const auto fullPath = m_dataPath + file;
	std::shared_ptr<Mesh> mesh{ new Mesh(pDevice, file, pEffect)};
	m_Meshes[file] = mesh;

	return m_Meshes[file];
}

