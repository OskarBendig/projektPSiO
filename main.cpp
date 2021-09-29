#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int windowWidth = 600;
int windowHeight = 800;
int halfWidth = windowWidth/2;
int halfHeight = windowHeight/2;


int main(){
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Square Up");
    window.setFramerateLimit(60);

    int x = 0;
    int y = 0;
    int w = 50;
    int h = 50;

    Texture mc;
    mc.loadFromFile("data/images/mc.png");
    Sprite mcSprite(mc);
    //mcSprite.setScale(7, 7);
    Clock gameClock;



    Font font;
    font.loadFromFile("data/fonts/ITCBLKAD.TTF");

    Text hateWife("HATE MY WIFE", font, 50);

    while (window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }

        float fps = gameClock.restart().asMilliseconds();

        if(Keyboard::isKeyPressed(Keyboard::W)){
            y = -1;
        }
        if(Keyboard::isKeyPressed(Keyboard::S)){
            y = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
            x = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::A)){
            x = -1;
        }
        if(!(Keyboard::isKeyPressed(Keyboard::W)) && !(Keyboard::isKeyPressed(Keyboard::S))){
            y = 0;
        }
        if(!(Keyboard::isKeyPressed(Keyboard::D)) && !(Keyboard::isKeyPressed(Keyboard::A))){
            x = 0;
        }
        window.clear();

        window.draw(mcSprite);
        mcSprite.move(x * fps, y *fps);

        window.draw(hateWife);

        window.display();

    }
    return 0;
}
