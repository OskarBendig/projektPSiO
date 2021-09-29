#include <platform.h>
#include <stdlib.h>

//potrzebny poprawny generator liczb losowych :)
platform::platform(){
    setX(rand()%600);
    setY(rand()%750);
    setLen(100);
    setHig(25);
    initPlatform();
}

platform::~platform(){}

bool platform::wasTouched(){
    return touched;
}

bool platform::collideUp(object *mc){
    return (mc->getX()-mc->getLen()/2 < this->getX() + this->getLen() && mc->getX() + mc->getLen()/2 > this->getX() &&
            mc->getY() + mc->getHig() > this->getY() && mc->getY() + 25 < this->getY() + this->getHig());
}

void platform::reset(){
            setY(rand()%100 * -1);
            setX(rand()%600);
            touched = false;
}

void platform::moveDown(float dy){
    setY(getY()-dy);
}

void platform::setTouch(bool a){
    touched = a;
}

void platform::initPlatform(){
    platformTex.loadFromFile("data/images/platform.png");
    platformSprite.setTexture(platformTex);
}

void platform::makeplatform(float a, float b){
    setX(a);
    setY(b);
}
