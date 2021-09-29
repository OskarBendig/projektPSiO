#ifndef SHAKER_H
#define SHAKER_H
#include <object.h>


class shaker: public object{
public:
    shaker();
    void initShak();
    void resetShak();
    void moveShak(float a);

    sf::Sprite shakerSprite;;
    sf::Texture shakerTex;
};

#endif // SHAKER_H
