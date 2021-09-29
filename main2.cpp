#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <game.h>


using namespace std;
using namespace sf;

int score;

int main(){

    score = 0;

    srand(time(0));

    game game;
    game.initGame();
    game.startingScreen();
    game.gameLoop();

    return 0;
}
