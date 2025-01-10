#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "component.hpp"

namespace sharbat {
	
	class entity
	{
	private:
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
	public:
		template <typename T, typename... Args>  
		void addComponent(Args&&... args) { //create a new component instance with the para
			components[std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
		}

		// Get a component
		template <typename T>
		T* getComponent() {
			auto it = components.find(std::type_index(typeid(T)));
			return it != components.end() ? static_cast<T*>(it->second.get()) : nullptr;
		}
	};
}