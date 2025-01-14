#pragma once

#include "Scene/scene.h"
#include "SFML/Graphics.hpp"

namespace sharbat {

	class SceneManager
	{
	public:
		void update(float deltaTime);
		void redraw(sf::RenderWindow& window);
		void changeScene(const Scene& nextScene);
	private:
		std::shared_ptr<Scene> current;
	};
}
