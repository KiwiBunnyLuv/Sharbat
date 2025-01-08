#pragma once
#include <string>
#include <vector>
#include "entity.h"

namespace sharbat {

	class Scene
	{
	private:
		std::string name;
		std::vector<entity> entities;

	public:
		void update();
		void redraw();
		void load();
		void unload();
	};
}
