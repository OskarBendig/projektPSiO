#include "hantel.h"

hantel::hantel(){
    setX(rand()%575);
    setY(800);
    setLen(25);
    setHig(25);
    initHan();
}

void hantel::moveHan(float b){
    setY(getY() - b);
}

void hantel::resetHantel(){
    setX(rand()%575);
    setY(-800);
}

void hantel::initHan(){
    hantelTex.loadFromFile("data/images/hantel.png");
    hantelSprite.setTexture(hantelTex);
}

