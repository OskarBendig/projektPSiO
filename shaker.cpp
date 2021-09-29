#include "shaker.h"

shaker::shaker(){
    setX(rand()%565);
    setY(-800);
    setLen(35);
    setHig(35);
    initShak();
}

void shaker::initShak(){
    shakerTex.loadFromFile("data/images/shaker.png");
    shakerSprite.setTexture(shakerTex);
}

void shaker::resetShak(){
    setX(rand()%565);
    setY(-800);
}

void shaker::moveShak(float a){
    setY(getY() - a);
}
