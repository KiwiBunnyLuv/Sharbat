#ifndef LABEL_HPP
#define LABEL_HPP

#include "GUI/Widget.hpp"

namespace sharbat {
    class Label : public Widget {
    public:
        Label(const sf::Font& font, const std::string& text, unsigned int size);

        void handleEvent(const sf::Event& event) override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;

    private:
        sf::Text label;
    };
}


#endif