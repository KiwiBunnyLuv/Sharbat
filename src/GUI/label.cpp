#include "GUI/label.h"

namespace sharbat {

    Label::Label(const sf::Font& font, const std::string& text, unsigned int size) {
        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(size);
        label.setFillColor(sf::Color::Black);
    }

    void Label::handleEvent(const sf::Event&) {
        // Labels do not handle events.
    }

    void Label::update(float) {
        // Labels typically don't update over time.
    }

    void Label::render(sf::RenderWindow& window) {
        window.draw(label);
    }

}