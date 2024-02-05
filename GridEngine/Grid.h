
struct SDL_Window;

namespace grid
{

	class Grid final
	{
	public:
		Grid() = default;
		~Grid() = default;

		void Run();
	private:

		void ShutDown(SDL_Window* pWindow);


		const int m_WindowWidth{ 1280 };
		const int m_WindowHeight{ 720 };

	};
}


