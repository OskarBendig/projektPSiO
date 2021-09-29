#ifndef MC_H
#define MC_H
#include <object.h>
#include <SFML/Graphics.hpp>


class mc: public object{
public:
    mc();
    ~mc();
    void move(float a, float b);
    void setPosition(float a, float b);
    void initMc();
    bool isDead();
    void updatePosition();
    sf::Sprite mcSprite;
    sf::Texture mcTex;
private:

};

#endif // MC_H
