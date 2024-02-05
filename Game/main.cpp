#include "pch.h"

#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Grid.h"

int main(int, char* []) {
	grid::Grid engine{};
	engine.Run();
	return 0;
}