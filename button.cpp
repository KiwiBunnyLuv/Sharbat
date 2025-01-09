// Button.cpp
#include "Button.hpp"
namespace sharbat {

    Button::Button(const sf::Vector2f& size, const sf::Font& font, const std::string& text) {
        shape.setSize(size);
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color::Black);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(20);
        label.setFillColor(sf::Color::Black);

        // Center the text inside the button
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        label.setPosition(size.x / 2, size.y / 2);
    }

    void Button::handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
            isHovered = shape.getGlobalBounds().contains(mousePos);
            shape.setFillColor(isHovered ? sf::Color::Green : sf::Color::White);
        }
        else if (event.type == sf::Event::MouseButtonPressed && isHovered) {
            if (callback)
                callback();
        }
    }

    void Button::update(float deltaTime) {
        // Additional animations or states can be handled here.
    }

    void Button::render(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(label);
    }

    void Button::setCallback(std::function<void()> callback) {
        this->callback = callback;
    }

}
