#include "SFML/Graphics.hpp"

#include <SFML/Window.hpp>
#include <unordered_map>
#include <functional>

namespace sharbat {
	class inputHandler {
    public:
        inputHandler();

        void handleEvent(const sf::Event& event);
        bool isKeyPressed(sf::Keyboard::Key key) const;
        bool isMouseButtonPressed(sf::Mouse::Button button) const;
        sf::Vector2i getMousePosition(const sf::RenderWindow& window) const;

        void bindKeyAction(sf::Keyboard::Key key, std::function<void()> action);
        void bindMouseAction(sf::Mouse::Button button, std::function<void()> action);
    private:
        std::unordered_map<sf::Keyboard::Key, bool> keyStates;
        std::unordered_map<sf::Mouse::Button, bool> mouseButtonStates;

        sf::Vector2i mousePosition;

        std::unordered_map<sf::Keyboard::Key, std::function<void()>> keyCallbacks;
        std::unordered_map<sf::Mouse::Button, std::function<void()>> mouseCallbacks;
	};
}