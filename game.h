#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <platform.h>
#include <mc.h>
#include <hantel.h>
#include <shaker.h>
#include <Windows.h>
#include <conio.h>


class game{
public:
    game();
    void initGame();
    void initWindow();
    void initFonts();
    void initMusic();
    void initTex();
    void cleanUp();
    void makePlats();
    void gameLoop();
    void windowEvent();
    void platformsDown();
    void bounce();
    void draw();
    void startingScreen();
    void loosingScreen();
    void makeHan();
    void drawHan();
    void bonked();
    void resetHan();
    void makeShaks();
    void drink();
    void drawShak();
    void showScore();

private:
    float h = 200;
    float dy = 0;
    int score = 0;
    int nrHan = 0;
    bool drinked = false;
    double startTime = GetTickCount();
    bool flip = false;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text points;


    sf::SoundBuffer buffer;
    sf::Sound music;
    sf::SoundBuffer buffer2;
    sf::Sound hit;
    sf::Texture backgroundTex, startTex, menuTex, looseTex;
    sf::Sprite backgroundSprite, startSprite, menuSprite, looseSprite;
    mc mc;
    platform *platforms[20];
    platform starter;
    hantel *hantle[7];
    shaker *shak;
};

#endif // GAME_H
