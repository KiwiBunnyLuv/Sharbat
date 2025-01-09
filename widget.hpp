// Widget.hpp
#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics.hpp>

namespace sharbat {

    class Widget {
    public:
        virtual ~Widget() = default;

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(float deltaTime) = 0;
        virtual void render(sf::RenderWindow& window) = 0;

        void setPosition(float x, float y) { position = { x, y }; }
        sf::Vector2f getPosition() const { return position; }

    protected:
        sf::Vector2f position;
    };
}

#endif