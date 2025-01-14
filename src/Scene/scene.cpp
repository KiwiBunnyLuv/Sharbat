#include "Scene/scene.h"

namespace sharbat {
    template <typename T, typename... Args>
    void Scene::addEntity(Args&&... args) {
        static_assert(std::is_base_of<Entity, T>::value, "T must inherit from Entity");
        std::type_index type = typeid(T);

        // Replace the existing entity of the same type if it already exists
        entities[type] = std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    T* Scene::getEntity() {
        static_assert(std::is_base_of<Entity, T>::value, "T must inherit from Entity");
        std::type_index type = typeid(T);

        auto it = entities.find(type);
        if (it != entities.end()) {
            return dynamic_cast<T*>(it->second.get());
        }
        return nullptr; // Return nullptr if the entity of type T doesn't exist
    }

    void Scene::update(float delatTime) {
        for (auto& [type, entity] : entities) {
            entity->update();
        }
    }

    void Scene::redraw() {
        for (auto& [type, entity] : entities) {
            entity->redraw();
        }
    }

    void Scene::load() {
        std::cout << "Scene loaded.\n";
        // Add any resource initialization logic here
    }

    void Scene::unload() {
        std::cout << "Scene unloaded.\n";
        entities.clear(); // Remove all entities when unloading the scene
    }
}