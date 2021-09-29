#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>


class object{
public:
    object();
    ~object();
    bool collide(object *other);
    float getX();
    float getY();
    float getLen();
    float getHig();
protected:
    void setX(float x);
    void setY(float y);
    void setLen(float len);
    void setHig(float hig);
private:
    float ox;
    float oy;
    float olen;
    float ohig;
};

#endif
