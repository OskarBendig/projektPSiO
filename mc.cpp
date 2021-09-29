#include "mc.h"

mc::mc(){
    setX(25);
    setY(700);
    setLen(50);
    setHig(50);
    initMc();
}

mc::~mc(){}

void mc::move(float a, float b){
    setX(getX() + a);
    setY(getY() + b);
}

void mc::setPosition(float a, float b){
    setX(a);
    setY(b);
}

void mc::initMc(){
    mcTex.loadFromFile("data/images/mc.png");
    mcSprite.setTexture(mcTex);
    mcSprite.setOrigin(50, 0);
}

bool mc::isDead(){
    if(getY() >= 800){
        return true;
    }else return false;

}

void mc::updatePosition(){
    if(getX() > 600){
        setPosition(getX()-600, getY());
        mcSprite.setPosition(getX(), getY());
    }else if(getX() < 0){
        setPosition(600-getX(), getY());
        mcSprite.setPosition(getX(), getY());
    }else{
        mcSprite.setPosition(getX(), getY());
    }
}
