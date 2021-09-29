#ifndef HANTEL_H
#define HANTEL_H
#include <object.h>
#include <SFML/Graphics.hpp>

class hantel: public object{
public:
    hantel();
    void moveHan(float b);
    void initHan();
    void resetHantel();

    sf::Sprite hantelSprite;;
    sf::Texture hantelTex;
};

#endif // HANTEL_H
