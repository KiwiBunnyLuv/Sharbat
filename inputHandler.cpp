#include "inputHandler.hpp"

namespace sharbat {

    inputHandler::inputHandler() {
        // Initialize all key and mouse states to false
        for (int key = sf::Keyboard::A; key <= sf::Keyboard::KeyCount; ++key) {
            keyStates[static_cast<sf::Keyboard::Key>(key)] = false;
        }
        for (int button = sf::Mouse::Left; button <= sf::Mouse::ButtonCount; ++button) {
            mouseButtonStates[static_cast<sf::Mouse::Button>(button)] = false;
        }
    }

    void inputHandler::handleEvent(const sf::Event& event) {
        // Handle keyboard events
        if (event.type == sf::Event::KeyPressed) {
            keyStates[event.key.code] = true;
            if (keyCallbacks.find(event.key.code) != keyCallbacks.end()) {
                keyCallbacks[event.key.code](); // Call the bound action
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            keyStates[event.key.code] = false;
        }

        // Handle mouse button events
        if (event.type == sf::Event::MouseButtonPressed) {
            mouseButtonStates[event.mouseButton.button] = true;
            if (mouseCallbacks.find(event.mouseButton.button) != mouseCallbacks.end()) {
                mouseCallbacks[event.mouseButton.button](); // Call the bound action
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            mouseButtonStates[event.mouseButton.button] = false;
        }

        // Handle mouse movement
        if (event.type == sf::Event::MouseMoved) {
            mousePosition = { event.mouseMove.x, event.mouseMove.y };
        }
    }

    bool inputHandler::isKeyPressed(sf::Keyboard::Key key) const {
        auto it = keyStates.find(key);
        return it != keyStates.end() ? it->second : false;
    }

    bool inputHandler::isMouseButtonPressed(sf::Mouse::Button button) const {
        auto it = mouseButtonStates.find(button);
        return it != mouseButtonStates.end() ? it->second : false;
    }

    sf::Vector2i inputHandler::getMousePosition(const sf::RenderWindow& window) const {
        return sf::Mouse::getPosition(window);
    }

    void inputHandler::bindKeyAction(sf::Keyboard::Key key, std::function<void()> action) {
        keyCallbacks[key] = action;
    }

    void inputHandler::bindMouseAction(sf::Mouse::Button button, std::function<void()> action) {
        mouseCallbacks[button] = action;
    }

}