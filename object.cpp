#include "object.h"

object::object(){

}

object::~object(){

}

bool object::collide(object *other){
    return (other->getX() - (other->getLen()/2) < this->getX() + this->getLen() &&
            other->getX() + other->getLen()/2 > this->getX() - this->getLen() &&
            other->getY() < this->getY() + this->getHig() &&
            other->getY() + other->getHig() > this->getY());
}

float object::getX(){
    return ox;
}

float object::getY(){
    return oy;
}

float object::getLen(){
    return olen;
}

float object::getHig(){
    return ohig;
}

void object::setX(float x){
    ox = x;
}

void object::setY(float y){
    oy = y;
}

void object::setLen(float len){
    olen = len;
}

void object::setHig(float hig){
    ohig = hig;
}

