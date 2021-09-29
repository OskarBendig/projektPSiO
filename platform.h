#include <object.h>

class platform: public object{
public:
    platform();
    ~platform();

    bool wasTouched();
    void reset();
    void moveDown(float dy);
    void setTouch(bool a);
    bool collideUp(object *mc);
    void initPlatform();
    void makeplatform(float a, float b);
    sf::Sprite platformSprite;;
    sf::Texture platformTex;
private:
    bool touched;
};
