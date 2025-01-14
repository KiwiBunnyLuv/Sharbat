#pragma once
#include <string>
#include <unordered_map>
#include <typeindex>
#include <iostream>
#include <memory>
#include "architecture/entity.hpp"

namespace sharbat {

	class Scene
	{
	public:
		template <typename T, typename... Args>
		void addEntity(Args&&... args);

		template <typename T>
		T* getEntity();

		void update(float deltaTime);
		void redraw();
		void load();
		void unload();

	private:
		std::unordered_map<std::type_index, std::unique_ptr<entity>> entities;

	};
}
