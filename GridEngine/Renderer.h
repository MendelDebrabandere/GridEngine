#pragma once

struct SDL_Window;
struct SDL_Surface;

namespace grid
{

	class Mesh;
	class Camera;

	class Renderer final
	{
	public:
		Renderer(SDL_Window* pWindow);
		~Renderer();

		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) noexcept = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		void Update(const Timer* pTimer);
		void Render() const;
		void ToggleRotation();
		void ToggleFilteringMethod();

	private:
		void InitMeshes();

		SDL_Window* m_pWindow{};

		int m_Width{};
		int m_Height{};

		bool m_IsInitialized{ false };

		std::vector<Mesh*> m_MeshPtrs{};
		Camera* m_pCamera{ nullptr };



		//DIRECTX
		HRESULT InitializeDirectX();
		//...

		enum class FilteringMethod
		{
			Point = 0,
			Linear = 1,
			Anisotropic = 2
		};

		FilteringMethod m_FilteringMethod{ 0 };

	};
}
