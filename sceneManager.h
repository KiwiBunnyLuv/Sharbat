#pragma once

#include "scene.h"

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
