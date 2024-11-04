#ifndef _TEXT_INPUT_FIELD_HPP_
#define _TEXT_INPUT_FIELD_HPP_

#include <cstdint>
#include <string>

#include <SFML/Graphics.hpp>

const uint8_t PIXELS_TO_CHAR = 15;
const uint8_t INPUT_FIELD_HEIGHT = 20;

class TextInputField: public sf::Drawable {
  public:
    TextInputField(float x, float y, uint16_t maxInputLength, const std::string& label, const sf::Font& font);

    const std::string& getInput() const;
    void handleInput(sf::Event event);
    void setFocus(bool focus);
    void setInput(const std::string& newInput);
    bool contains(sf::Vector2f point) const;

  protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  private:
    uint16_t maxInputLength_;
    sf::Text label_;
    sf::Text text_;
    std::string input_;
    sf::RectangleShape inputField_;
    bool hasFocus_;
}; 

#include "../src/TextInputField.cpp"

#endif // _TEXT_INPUT_FIELD_HPP_