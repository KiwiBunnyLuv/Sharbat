#pragma once

#include "scene.hpp"

namespace sharbat {

	class SceneManager
	{
	private:
		Scene current;
	public:
		void update();
		void redraw();
		void changeScene(const Scene& nextScene)
	};
}
