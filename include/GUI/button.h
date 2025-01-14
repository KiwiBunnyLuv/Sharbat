#pragma once
#include "GUI/widget.hpp"
#include <functional>
#include "SFML/Graphics.hpp"

namespace sharbat {

class Button : public Widget {
public:
    Button(const sf::Vector2f& size, const sf::Font& font, const std::string& text);

    void handleEvent(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void setCallback(std::function<void()> callback);

private:
    sf::RectangleShape shape;
    sf::Text label;
    std::function<void()> callback;
    bool isHovered = false;
};


}

