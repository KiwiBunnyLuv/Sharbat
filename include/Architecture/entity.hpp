#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "architecture/component.hpp"

namespace sharbat {
	
	class entity
	{
	public:
		template <typename T, typename... Args>  
		void addComponent(Args&&... args) { 
			components[std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
		}

		template <typename T>
		T* getComponent() {
			auto it = components.find(std::type_index(typeid(T)));
			return it != components.end() ? static_cast<T*>(it->second.get()) : nullptr;
		}

	private:
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
	};
}