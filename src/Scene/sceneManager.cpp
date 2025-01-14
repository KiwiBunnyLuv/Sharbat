#include "Scene/sceneManager.h"

namespace sharbat {
	void SceneManager::update(float deltaTime)
	{
		if (current) {
			current->update(deltaTime);
		}
	}
	void SceneManager::redraw(sf::RenderWindow& window)
	{
		if (current) {
			current->redraw(window);
		}
	}
	void SceneManager::changeScene(const Scene& nextScene)
	{
	}
}