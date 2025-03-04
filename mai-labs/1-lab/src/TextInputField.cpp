#include "../include/TextInputField.h"

TextInputField::TextInputField(float x, float y, uint16_t maxInputLength, const std::string& label, const sf::Font& font) :
    maxInputLength_(maxInputLength), 
    inputField_(sf::Vector2f(PIXELS_TO_CHAR * maxInputLength_, INPUT_FIELD_HEIGHT)),
    label_(label, font, 20), 
    text_("", font, 20), 
    input_("")
{
    label_.setPosition(x, y);
    label_.setFillColor(sf::Color::Black);

    text_.setPosition(x + 50, y);
    text_.setFillColor(sf::Color::Yellow);

    inputField_.setOutlineThickness(2);
    inputField_.setFillColor(sf::Color::Black);
    inputField_.setOutlineColor(sf::Color(127, 127, 127));
    inputField_.setPosition(x + 40, y);
}

inline const std::string& TextInputField::getInput() const {
    return input_;
}

void TextInputField::handleInput(sf::Event event) {
    if (hasFocus_ && event.type == sf::Event::TextEntered && event.text.unicode < 128) { // only ASCII symbols
        if (event.text.unicode == 8 && !input_.empty()) { // Backspace
            input_.pop_back();
        } else if (input_.length() < maxInputLength_) {
            input_ += static_cast<char>(event.text.unicode);
        }

        text_.setString(input_);
    }
}

void TextInputField::setFocus(bool focus) {
    hasFocus_ = focus;

    if (focus) {
        inputField_.setOutlineColor(sf::Color::Blue);

        return;
    }

    inputField_.setOutlineColor(sf::Color(127, 127, 127));
}

inline void TextInputField::setInput(const std::string& newInput) {
    input_ = newInput;
    text_.setString(input_);
}

inline bool TextInputField::contains(sf::Vector2f point) const {
    return inputField_.getGlobalBounds().contains(point);
}

void TextInputField::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(label_, states);
    target.draw(inputField_, states);
    target.draw(text_, states);
}
